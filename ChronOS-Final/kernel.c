/*
*  kernel.c
*/


#include "library.h"
#include "logo.h"
#include "keyboard.h"
//#include "input.h"


void loadingscreen(void);

// 0x<bg><fg>
#define Black 0x00 
#define Blue 0x01
#define Green 0x02
#define Cyan 0x03
#define Red 0x04
#define Magenta 0x05
#define Brown 0x06
#define LightGrey 0x07
#define DarkGrey 0x08
#define LightBlue 0x09
#define LightGreen 0x0a
#define LightCyan 0x0b
#define LightRed 0x0c
#define LightMagenta 0x0d
#define Yellow 0x0e
#define White 0x0f



void kmain(void)
{
	char *str = "ChronOS: Operating System of Gods";
	char *text1 = "This OS does nothing but this.";
	char *text2 = "Additional features will be added soon...";
	char *text3 = "(c) Jude Teves";
	//char *test = 0x5c
	//char *vidptr = (char*)0xb8000; 	//video mem begins here.
	//unsigned int i = 0;
	//unsigned int j = 0;
	
	//loadingscreen();
	
	//clearscreen();
	//index = 1600;
	//printc("ChronOS: Operating System of Gods", Cyan);
		
	clearscreen();
	index = 0;
	printc("ChronOS: Operating System of Gods", Cyan);
	//index = 1600;
	
	//__asm__ __volatile__ ("sti");	//enables interrupts

		
	//enable_interrupts();
	//restart_keyboard();
	//while(1) {
	//__asm__ __volatile__ ("sti");	//enables interrupts
	//keyboard_handler();
	//__asm__ __volatile__ ("cli");	//disables interrupts
	//}
	
	//__asm__ __volatile__ ("cli");	//disables interrupts
	
	//unsigned int c;
	
	//c = '\0';
	
	//while(c != 0x2E) {
	//	c = inportb(0x60);
		
	//}
	
	//index = 1600;
	//print("Hello World!");
	
	__asm__ __volatile__ ("cli");	//disables interrupts
	
	index = 480;
//	char ch;
//	while(1) {
//		ch = '\0';
//		while(ch == '\0') {
//			ch = input();
//		}
		
//		printchar(ch);
		//delay();
		//index+=2;
//	}
	
	loadingscreen();
	//in();
	


	return;
}


void loadingscreen() {
	unsigned int offset_y = 320;
	unsigned int offset_x = 30;
	unsigned int i = 0;
	unsigned int j = 0;	
	
	index = 3200;
	
	while(1) {
		
		logo(offset_y, offset_x);	
		//0x9c == enter released
		//0x01 == esc pressed
		//0x29 == console key ` or ~
		if(inportb(0x60) == 0x1c){
			//print("Hello World!");
			//while(inportb(0x60)!=)
			in();
		}
	}
}


