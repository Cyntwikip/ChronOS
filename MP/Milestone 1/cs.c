
#include "system.h"

//Milestone 1
//char getch();
//char* gets();
//int getInt();
//void printInt(int num);


char getch() {
	
	return 'c';
}

char* gets() {
	char *c;
	
	return c;
}

int getInt() {
	
	
	return 0;
}

void printInt(int num) {
	char *charnum;
	char c;
	int tempnum=0;
	int i=0;
	int digits=0;
	int onenum;
	
	//counts the number of digits
	while(num>tempnum) {
		digits++;
		
		if(tempnum==0)
			tempnum = 10;
		else
			tempnum *= 10;
	}
	//if number is 0
	if(digits==0)
		digits = 1;
	
	tempnum = 0;
	
	//putch(digits + 48);	//number of digits
	
	//converts all integer numbers to string
	while(digits > 0) {
		//c = (char) 
		onenum = num%power(10, digits);	//eliminate all numbers at the right
		
		onenum = onenum/power(10, digits-1);	//eliminate all numbers at the left
			
		c = (char) (onenum + 48);	//Integer to Character
		
		//c = 56;
		putch(c);
		charnum[i] = c;	//store the character into string
		
		i++;
		digits--;
		
	}
	charnum[i] = '\0';	//end of string
	putch('\n');
	puts(charnum);
	//puts("1234");
	//putch(50);
	timer_wait(18);
	
	return;
}

int power(int base, int exponent) {
	int number;
	int i;
	
	if(exponent == 0)
		return 1;
	
	number = base;
	
	for(i=0; i<exponent-1; i++) {
		number = number*base;		
	}

	return number;
}
