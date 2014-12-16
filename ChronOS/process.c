
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
	int x=0;
	while(1) {
		timer_wait(6);
		//putch('A');
		putch('\n');
		printInt(x++);
	}
}

void testprogram() {

	putch('\n');

	while(1) {
		putch('\n');
		puts("Hi");
		timer_wait(6);
	}
	
}
