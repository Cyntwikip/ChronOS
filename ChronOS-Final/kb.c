/* bkerndev - Bran's Kernel Development Tutorial
*  By:   Brandon F. (friesenb@gmail.com)
*  Desc: Keyboard driver
*
*  Notes: No warranty expressed or implied. Use at own risk. */
#include "system.h"
#include "shell.h"

//static unsigned char *string;
//static unsigned int si=0;	//string index

/* KBDUS means US Keyboard Layout. This is a scancode table
*  used to layout a standard US keyboard. I have left some
*  comments in to give you an idea of what key is what, even
*  though I set it's array index to 0. You can change that to
*  whatever you want using a macro, if you wish! */
unsigned char kbdus[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',		/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,					/* Right shift */
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
    0,	/* All other keys are undefined */
};

unsigned char shiftkeys [128] = {0,  27, '!', '@', '#', '$', '%', '^', '&', '*',	/* 9 */
  '(', ')', '_', '+', '\b',	/* Backspace */
  '\t',			/* Tab */
  'Q', 'W', 'E', 'R',	/* 19 */
  'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':',	/* 39 */
 '"', '~',   0,		/* Left shift */
 '|', 'Z', 'X', 'C', 'V', 'B', 'N',			/* 49 */
  'M', '<', '>', '?',   0,				/* Right shift */
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

unsigned int caps = 0;

/*
	Guide:
	
	if (scancode & 0x80) -> does nothing for key releases
	else if(kbdus[scancode] == 0) -> does nothing for keys that do not have a value yet...
	else if (caps == 1) -> for uppercase
	else -> for lowercase
	
*/

/* Handles the keyboard interrupt */
void keyboard_handler(struct regs *r)
{
    unsigned int scancode;
    unsigned int shift;
    unsigned char key;
    
    /* Read from the keyboard's data buffer */
    scancode = inportb(0x60);
       
    /* this is for context switching */ 
    if(kbdus[scancode] == '`') {
	
		cs(r);
		scancode = 0;
        //puts("\nDone changing the registers... Will switch in a moment...\n");
        //delay(10000);
        return;
        //puts("Already returned!\n");
	}
	
	//All processes can exit except Process 0 which is the main program.
	if(scancode == 0x01 && p_curr != 0) {
		exitp(r);
		return;
	}
	
	if(p_curr != 0) {
		return;
	}
    
    if(scancode == 0x3A) {
		if(caps == 0)
			caps = 1;
		else
			caps = 0;
		//puts("caps\n");
	}	

    /* If the top bit of the byte we read from the keyboard is
    *  set, that means that a key has just been released */
    if (scancode & 0x80)
    {
        /* You can use this one to see if the user released the
        *  shift, alt, or control keys... */
        //puts("release");
                
    }
    
    //catches some keys Ex. Caps Lock = 0x3A  Delete = 0x53
    //else if (scancode == 0x3A || scancode == 0x53) {
	else if(kbdus[scancode] == 0) {
		
	}
    else if (caps == 1) {
		shell(shiftkeys[scancode]);
		//key = shiftkeys[scancode];
		//puts(" UPPERCASE ");
	}
    else
    {
        /* Here, a key was just pressed. Please note that if you
        *  hold a key down, you will get repeated key press
        *  interrupts. */

        /* Just to show you how this works, we simply translate
        *  the keyboard scancode into an ASCII value, and then
        *  display it to the screen. You can get creative and
        *  use some flags to see if a shift is pressed and use a
        *  different layout, or you can add another 128 entries
        *  to the above layout to correspond to 'shift' being
        *  held. If shift is held using the larger lookup table,
        *  you would add 128 to the scancode when you look for it */
        
        shell(kbdus[scancode]);
        //shell(shiftkeys[scancode]);
        //putch(kbdus[scancode]);
        //puts("lowercase");
        
    }
}

/* Installs the keyboard handler into IRQ1 */
void keyboard_install()
{
    irq_install_handler(1, keyboard_handler);
}
