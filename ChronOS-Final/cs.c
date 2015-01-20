
#include "system.h"

//Milestone 1
//char getch();
//char* gets();
//int getInt();
//void printInt(int num);


process processes[20];
int p_curr;
int p_limit;

//int memloc1 = 0x00120000;
//int memloc2 = 0x00130000;
//int memloc1 = 0x2000;
//int memloc2 = 0x3000;

//int *ptr1;
//int *ptr2;

void cs_init() {
	//ptr1 = (int*) memloc1;
	//ptr2 = (int*) memloc2;
	
	//int memloc1;
	//int memloc2;
	//int memloc3;
	
	//memloc1 = malloc(200);
	//memloc2 = malloc(200);
	//memloc3 = malloc(200);
	
	//printInt(x);
	//printInt(y);
	//printInt(rand);
	
	//Why 68? Why add 68 to the memloc. Through trial and error, I found out that targetesp moves -68 bytes...
	//from its original location. Dunno what's with that value but hey this thing works!
	//If I dont add 68, when the memory block allocated for a process is freed, the data for the next...
	//process will be corrupted.
	
	//memloc1 += 68;	
	//memloc2 += 68;	
	//memloc3 += 68;
						
	
	//processes[1].stack = memloc1;
	//processes[2].stack = memloc2;
	//processes[3].stack = memloc3;

	processes[0].isInit = 1;// coz this is main!
	processes[0].active = 1;

	//processes[1].esp = memloc1;
	//processes[1].ebp = memloc1 + 19;
	//processes[1].eip = &proc1;
	//processes[1].isInit = 0;

	//processes[2].esp = memloc2;
	//processes[2].ebp = memloc2 + 19;
	//processes[2].eip = &proc2;
	//processes[2].isInit = 0;
	
	//processes[3].esp = memloc3;
	//processes[3].ebp = memloc3 + 19;
	//processes[3].eip = &testprogram;
	//processes[3].isInit = 0;
	
	
	p_curr = 0;
	//p_limit = 4;
	p_limit = 1;
}

void cs(struct regs *r) {	

	init_video();

	processes[p_curr].targetesp = r->targetesp;// backs up the targetesp of the generated Interrupt Frame for the last process.
	//printInt((processes[p_curr].targetesp));
	//putch('\n');
	
	/*
	int p_next = p_curr+1;
	if(p_next == p_limit)
		p_next = 0;	
	*/
	
	int p_next = p_curr;	
	do {	
		p_next = p_next+1;
		if(p_next == p_limit)
			p_next = 0;	
	} while(processes[p_next].active != 1);
	

	//p_next = 1;
	
	//if(p_next == 1 && processes[p_next].isInit == 1)
	//r->targetesp = 1073156 - 68; //1073156
	
	//if(p_next == 2 && processes[p_next].isInit == 1)
	//r->targetesp = 1077156 - 68; //1077156

	// if the interrupt frame is not initialized...
	if(processes[p_next].isInit != 1) {	
		
		//if(p_next == 2)
		//	puts("lala");
		
		puts("Initializing Interrupt Frame for ");
		//timer_wait(1);
		//delay(1000);
		processes[p_next].stack[0] = processes[p_next].stack + 1; //which is targetestp contains the pointer to gs
		processes[p_next].stack[1] = r->gs;
		processes[p_next].stack[2] = r->fs;
		processes[p_next].stack[3] = r->es;
		processes[p_next].stack[4] = r->ds;
		processes[p_next].stack[5] = r->edi;
		processes[p_next].stack[6] = r->esi;
		processes[p_next].stack[7] = processes[p_next].ebp;
		processes[p_next].stack[8] = processes[p_next].esp;
		processes[p_next].stack[9] = r->ebx;
		processes[p_next].stack[10] = r->edx;
		processes[p_next].stack[11] = r->ecx;
		processes[p_next].stack[12] = r->eax;
		processes[p_next].stack[13] = r->int_no;
		processes[p_next].stack[14] = r->err_code;
		processes[p_next].stack[15] = processes[p_next].eip;
		processes[p_next].stack[16] = r->cs;
		processes[p_next].stack[17] = r->eflags;
		processes[p_next].stack[18] = r->useresp;
		processes[p_next].stack[19] = r->ss;

		processes[p_next].isInit = 1;
		processes[p_next].targetesp = processes[p_next].stack[0];
	}

	p_curr = p_next;
	
	if(p_curr == 0) {
		displayOS();
	}
	
	else {
		puts("Process ");		
		printInt(p_curr);
		
		putch('\n');
		//printInt((processes[p_curr].targetesp));
		//putch('\n');
	}
	
	//delay(10000);	
	
	r->targetesp = processes[p_curr].targetesp;	
		//putch('\n');
		//printInt((processes[p_curr].targetesp));
		//printInt(r->targetesp);
		//putch('\n');	
}

void exitp(struct regs *r) {
	unsigned int success=0;
	success = freealloc(processes[p_curr].stack);
	processes[p_curr].isInit = 0;	
	processes[p_curr].active = 0;
		
	init_video();
	displayOS();
	
	p_curr = 0;
	
	r->targetesp = processes[0].targetesp;
}

char getch() {
	unsigned int scancode;
    unsigned int shift;
    unsigned char key;
    
    /* Read from the keyboard's data buffer */
    scancode = inportb(0x60);
	
	/* If the top bit of the byte we read from the keyboard is
    *  set, that means that a key has just been released */
    if (scancode & 0x80)
    {
        /* You can use this one to see if the user released the
        *  shift, alt, or control keys... */
        //puts("release");                
    }    
    else
    {
        return kbdus[scancode];
    }
	return '\0';
}

char* gets() {
	char *c;
	
	return c;
}

int getInt(char* num) {
	
	
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
	while(num>=tempnum) {
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
		//putch(c);
		charnum[i] = c;	//store the character into string
		
		i++;
		digits--;
		
	}
	charnum[i] = '\0';	//end of string
	//putch('\n');
	puts(charnum);
	//puts("1234");
	//putch(50);
	//timer_wait(18);
	//putch('\n');
	
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

