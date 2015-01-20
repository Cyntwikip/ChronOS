
#include "system.h"

void func1() {
	int x=0;
	while(1) {
		timer_wait(6);
		//putch('A');
		putch('\n');
		printInt(x++);
	}
}

void func2() {
	int x=0;
	while(1) {
		timer_wait(6);
		//putch('A');
		putch('\n');
		printInt(x++);
	}
}

void func3() {
	puts("OLAA!!");
	
	//getch();
	//timer_wait(72);
	while(1) {}
	
	//exitp();
}

void testprogram() {

	putch('\n');

	while(1) {
		putch('\n');
		puts("Hi");
		timer_wait(6);
	}
	
}
