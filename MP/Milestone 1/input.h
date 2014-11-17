// Resources:
// http://kernelx.weebly.com/getting-keyboard-input.html
// http://www.osdever.net/bkerndev/Docs/keyboard.htm

//0x60 :Data Register(Read\Write)
//0x64:Command Register(Read\Write)

/* This defines what the stack looks like after an ISR was running */
struct regs
{
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;    
};

unsigned int restart_keyboard()
{    
   int data = inportb(0x61);     
   outportb(0x61,data | 0x80);//Disables the keyboard  
   outportb(0x61,data & 0x7F);//Enables the keyboard  
   return 0;
}

//Getting the scancode from keyboard controller:

unsigned char get_scancode()
{
    unsigned char inputdata;
    //inputdata = inportb(KEYMOS_DATAREG );
    inputdata = inportb(0x60);
    return inputdata;
}

/* This is a scancode table
*  used to layout a standard US keyboard. I have left some
*  comments in to give you an idea of what key is what, even
*  though I set it's array index to 0. You can change that to
*  whatever you want using a macro, if you wish! */

//Processing the scancode:
unsigned char kblayout [128] = {0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */ };//Fill your layout yourself 
    
//void keyboard_handler(struct regs *r)
void keyboard_handler(void)
{ 
     unsigned char scancode; 
     unsigned int shift_key = 0;
     scancode = get_scancode();
     scancode = 4;
     
     if(scancode != '\0') {
		  printindex("HIIII!!", 1200, 0x07);
		  index = 1400;
		  printchar(kblayout[scancode]);
		  //index = 1410;
		  //print("4");
	 } 
	 
     while(scancode == '\0') {
	 scancode = get_scancode();
     if(scancode == 0x2A)     
     {
          shift_key = 1;//Shift key is pressed
     }      
     else if(scancode & 0xAA)
     {
          int shift_key= 0;//Shift Key is not pressed
     }      
     else    
     {          
         if (scancode & 0x80)
         {
              int shiftaltctrl = 1;//Put anything to see what special keys were pressed
         }
         else
         {  
              //printtxt(kblayout[scancode]); //Prints the character which was pressed    
              //index+=2;
              index = 1600;
              printchar(kblayout[scancode]);      
         }     
     }
	}
}

/*
void enable_interrupts ()
{
__asm__ (“sti”);//Enables the interrupts , set the interrupt flag
}
*/
