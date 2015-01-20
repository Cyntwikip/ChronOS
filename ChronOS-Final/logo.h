//ChronOS v5

void logo(unsigned int offset_y, unsigned int offset_x);
void hourglass(unsigned int offset_y, unsigned int offset_x);
void sand1(unsigned int offset_y, unsigned int offset_x);
void sand2(unsigned int offset_y, unsigned int offset_x);
void sand3(unsigned int offset_y, unsigned int offset_x);
void sand4(unsigned int offset_y, unsigned int offset_x);

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


void logo(unsigned int offset_y, unsigned int offset_x) {
	
		offset_y = 160*4;
		offset_x = 40;
		
		unsigned int i = 0;
		unsigned int j = 0;

	while(1) {	
		
		j=0;
		
		while(j<4) {	
			
		//j%=4;
		
		clearscreen();
		
		//OS
		i = 0;
		printindex("ChronOS: Operating System of Gods", i, Cyan);
		//Credits
		i = 3950;
		printindex("(c) Team ChronOS", i, Yellow);
		//Version
		i = 55*2;
		printindex("ChronOS-011", i, Yellow);
		i = 160+55*2;
		printindex("developed by Cyntwikip", i, LightCyan);	
		
		hourglass(offset_y, offset_x);
		
		switch(j) {
		case 0: sand1(offset_y, offset_x); break;	
		case 1: sand2(offset_y, offset_x); break;
		case 2: sand3(offset_y, offset_x); break;
		case 3: sand4(offset_y, offset_x); break;
		default: break;
		}
		
		i = 3520;
		printindex("Unicorn\tRainbow!!!", i, LightRed);	
		
		j++;
		
		
		timer_wait(6);
	
		}
	}
}

void hourglass(unsigned int offset_y, unsigned int offset_x) {
/*
	1 2 3 4 5 6 7 8 9
1	* * * * * * * * * 	
2	*               *
3	*               *
4	  *           *
5	    *       *  
6	      *   *
7	      *   *
8	    *       *
9	  *           *
10	*               *
11	*               *
12	* * * * * * * * * 
*/	

//unsigned int white = 0xff;
//unsigned int grey = 0x77;
unsigned int brown = 0x66;
unsigned int darkgrey = 0x88;
unsigned int yellow = 0xee;

printindex("123456789", offset_y+offset_x, brown); offset_y += 160;
printindex("1       9", offset_y+offset_x, darkgrey); offset_y += 160;	
printindex("1       9", offset_y+offset_x, darkgrey); offset_y += 160;
printindex(" 2     8 ", offset_y+offset_x, darkgrey); offset_y += 160;
printindex("  3   7  ", offset_y+offset_x, darkgrey); offset_y += 160;
printindex("   4 6   ", offset_y+offset_x, darkgrey); offset_y += 160;
printindex("   4 6   ", offset_y+offset_x, darkgrey); offset_y += 160;
printindex("  3   7  ", offset_y+offset_x, darkgrey); offset_y += 160;
printindex(" 2     8 ", offset_y+offset_x, darkgrey); offset_y += 160;
printindex("1       9", offset_y+offset_x, darkgrey); offset_y += 160;
printindex("1       9", offset_y+offset_x, darkgrey); offset_y += 160;
printindex("123456789", offset_y+offset_x, brown);	
	
}

void sand1(unsigned int offset_y, unsigned int offset_x) {

unsigned int brown = 0x66;
unsigned int darkgrey = 0x88;
unsigned int yellow = 0xee;

offset_y += 320;

printindex("   456   ", offset_y+offset_x, yellow); offset_y += 160;
printindex("  34567  ", offset_y+offset_x, yellow); offset_y += 160;
printindex("   456   ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("   456   ", offset_y+offset_x, yellow); offset_y += 160;
printindex("  34567  ", offset_y+offset_x, yellow); offset_y += 160;	
	
}

void sand2(unsigned int offset_y, unsigned int offset_x) {

unsigned int brown = 0x66;
unsigned int darkgrey = 0x88;
unsigned int yellow = 0xee;

offset_y += 320;

printindex("         ", offset_y+offset_x, yellow); offset_y += 160;
printindex("   456   ", offset_y+offset_x, yellow); offset_y += 160;
printindex("   456   ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("  345678 ", offset_y+offset_x, yellow); offset_y += 160;
printindex(" 2345678 ", offset_y+offset_x, yellow); offset_y += 160;
	
}

void sand3(unsigned int offset_y, unsigned int offset_x) {

unsigned int brown = 0x66;
unsigned int darkgrey = 0x88;
unsigned int yellow = 0xee;

offset_y += 320;

printindex("         ", offset_y+offset_x, yellow); offset_y += 160;
printindex("         ", offset_y+offset_x, yellow); offset_y += 160;
printindex("   456   ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("   456   ", offset_y+offset_x, yellow); offset_y += 160;
printindex(" 2345678 ", offset_y+offset_x, yellow); offset_y += 160;
printindex(" 2345678 ", offset_y+offset_x, yellow); offset_y += 160;	
	
}

void sand4(unsigned int offset_y, unsigned int offset_x) {

unsigned int brown = 0x66;
unsigned int darkgrey = 0x88;
unsigned int yellow = 0xee;

offset_y += 320;

printindex("         ", offset_y+offset_x, yellow); offset_y += 160;
printindex("         ", offset_y+offset_x, yellow); offset_y += 160;
printindex("         ", offset_y+offset_x, yellow); offset_y += 160;
printindex("         ", offset_y+offset_x, yellow); offset_y += 160;
printindex("    5    ", offset_y+offset_x, yellow); offset_y += 160;
printindex("   456   ", offset_y+offset_x, yellow); offset_y += 160;
printindex("  34567  ", offset_y+offset_x, yellow); offset_y += 160;
printindex(" 2345678 ", offset_y+offset_x, yellow); offset_y += 160;
printindex(" 2345678 ", offset_y+offset_x, yellow); offset_y += 160;		
	
}
