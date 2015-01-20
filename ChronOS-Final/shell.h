
#include "system.h";
#include "library.h";
#include "logo.h";
//#include "marquee.c";


void shell(unsigned char key);
void say(unsigned char *string);
void mrq(unsigned char *string);
//void marquee(void);
void clearstring(void);
void displayOS(void);
void init_video(void);

static unsigned char *string;
static unsigned int OSspace = 9;
unsigned int si;	//string index




void shell(unsigned char key) {
	
	if(key == '\n') {
		//for say command
		if(*string == 's' && *(string+1) == 'a' && *(string+2) == 'y' && *(string+3) == ' ')
			say(string);
		//for cls command
		else if(*string == 'c' && *(string+1) == 'l' && *(string+2) == 's') {
			init_video();
			si = 0;
			marquee_flag = 0;
			last_data_index = 0;
		}
		//for marquee command
		else if(*string == 'm' && *(string+1) == 'a' && *(string+2) == 'r' && *(string+3) == 'q' && *(string+4) == 'u' && *(string+5) == 'e' && *(string+6) == 'e' && *(string+7) == ' ') {
			mrq(string);
		}
		//for running processes
		//else if(*string == 'r' && *(string+1) == 'u' && *(string+2) == 'n' && *(string+3) == ' ' && *(string+4) == 'p' && *(string+5) == 'r' && *(string+6) == 'o' && *(string+7) == 'c' && *(string+8) == 'e' && *(string+9) == 's' && *(string+10) == 's') {
		else if(*string == 'r' && *(string+1) == 'u' && *(string+2) == 'n' && *(string+3) == ' ') {
			runprocess(string);
		}
		else {
			clearstring();
			si = 0;
			putch('\n');
		}
		
		displayOS();
		
	}
		
	else {				
		
		if(key == '\b' && si<=0) {	
			//do nothing  
		}
		
		else {
			if(key == '\b' && si > 0){
				*(string+si-1) = '\0';
				si--;
			}
			else {				
				//if(si>6) {
				//*(string+si) = '#';
				//si++;
				//}
				//else {
								
				*(string+si) = key;
				si++; 
								
				//}
				
				//if(key == 'D')
				//	puts("\nYou got a D!\n");
				//if(key != '') 
				
			}
			//if(si>4) {
			//*(string+si) = '#';
			//si++;
			//}
			putch(key);			
		}
	}
} 

void displayOS() {
	//puts("ChronOS> ");
	//unsigned int Cyan = 0x03;
	//putch('\n');
	printindex("ChronOS> ", csr_y*160, Cyan);
	csr_x = 9;
}

void say(unsigned char *string) {
	
	int i;	
	//putch(0x08);
	
	for(i=0; i<si; i++) {
		*(string+i) = *(string+i+4);
	}
	
	*(string+si-4) = '\0';	
	putch('\n');
	
	for(i=0; i<si-4; i++) {
		putch(*(string+i));
	}
	
	//puts(string);	//Weird... puts() terminates when uppercase letter appears...
	//puts(" END! ");	//but this works.... LOL!
	
	putch('\n');
	si = 0;	
	
	clearstring();		
}

void mrq(unsigned char *string) {
	
	int i;
	
	//putch('\n');
	for(i=0; i<si; i++) {
		*(string+i) = *(string+i+8);
		//putch(string[i]);
	}
	
	*(string+si-8) = '\0';	
	putch('\n');
	
	//temp_struct.m_str = string;
	/*
	for(i=0; i<=si-8; i++) {
		temp_struct.m_str[i] = string[i];
	}
	temp_struct.csr_y = csr_y;
	temp_struct.csr_x = 0;
	*/
	
	for(i=0; i<=si-8; i++) {
		m_struct[last_data_index].m_str[i] = string[i];
		//putch(m_struct[last_data_index].m_str[i]);
		//putch(string[i]);
		//temp_struct.m_str[i] = string[i];
		//putch(temp_struct.m_str[i]);
	}
	m_struct[last_data_index].csr_y = csr_y;
	m_struct[last_data_index].csr_x = 0;
	
	mi = si;
	
	//moving_string();
			
	putch('\n');
	//putch('\n');
	si = 0;	
	//clearstring();	
	
	last_data_index++;
	if(last_data_index==50)
		last_data_index = 1;
	marquee_flag = 1;
	//moving_string();
	//moving_string();

}


void clearstring() {
	
	int i=0;
	
	for(i=0; i<=si; i++) {
		*(string+i) = '\0';
	}
	
}

void runprocess(unsigned char* string) {
	int i;	
	
	for(i=0; i<si; i++) {
		*(string+i) = *(string+i+4);
	}
	
	*(string+si-4) = '\0';	
	
	//func1
	if(string[0] == 'f' && string[1] == 'u' && string[2] == 'n' && string[3] == 'c' && string[4] == '1' && string[5] == '\0') {
		int memloc = malloc(200);
		memloc += 68;
		
		
		while(processes[p_curr].active == 1) {
			p_curr++;
			if(p_curr == p_limit)
				p_limit++;
		}		
		//p_curr = p_limit;		
		//p_limit++;
		
		processes[p_curr].stack = memloc;
		processes[p_curr].esp = memloc;
		processes[p_curr].ebp = memloc + 19;
		processes[p_curr].eip = &func1;
		processes[p_curr].isInit = 0;
		processes[p_curr].active = 1;
		
		puts("\nFunc1 created");	
		p_curr = 0;		
	}
	//func2
	if(string[0] == 'f' && string[1] == 'u' && string[2] == 'n' && string[3] == 'c' && string[4] == '2' && string[5] == '\0') {
		int memloc = malloc(200);
		memloc += 68;
		
		while(processes[p_curr].active == 1) {
			p_curr++;
			if(p_curr == p_limit)
				p_limit++;
		}
		//p_curr = p_limit;		
		//p_limit++;
		
		processes[p_curr].stack = memloc;
		processes[p_curr].esp = memloc;
		processes[p_curr].ebp = memloc + 19;
		processes[p_curr].eip = &func2;
		processes[p_curr].isInit = 0;
		processes[p_curr].active = 1;	
		
		puts("\nFunc2 created");	
		p_curr = 0;		
	}
	//func3
	if(string[0] == 'f' && string[1] == 'u' && string[2] == 'n' && string[3] == 'c' && string[4] == '3' && string[5] == '\0') {
		int memloc = malloc(200);
		memloc += 68;
		
		while(processes[p_curr].active == 1) {
			p_curr++;
			if(p_curr == p_limit)
				p_limit++;
		}
		//p_curr = p_limit;		
		//p_limit++;
		
		processes[p_curr].stack = memloc;
		processes[p_curr].esp = memloc;
		processes[p_curr].ebp = memloc + 19;
		processes[p_curr].eip = &func3;
		processes[p_curr].isInit = 0;
		processes[p_curr].active = 1;	
		
		puts("\nFunc3 created");	
		p_curr = 0;		
	}
	
	if(string[0] == 'l' && string[1] == 'o' && string[2] == 'g' && string[3] == 'o' && string[4] == '\0') {
		int memloc = malloc(200);
		memloc += 68;
		
		while(processes[p_curr].active == 1) {
			p_curr++;
			if(p_curr == p_limit)
				p_limit++;
		}
		//p_curr = p_limit;		
		//p_limit++;
		
		processes[p_curr].stack = memloc;
		processes[p_curr].esp = memloc;
		processes[p_curr].ebp = memloc + 19;
		processes[p_curr].eip = &logo;
		processes[p_curr].isInit = 0;	
		processes[p_curr].active = 1;
		
		puts("\nChronOS Logo created");	
		p_curr = 0;	
	}
	
	putch('\n');
	si = 0;
	clearstring();
}

/*
void runprocess(unsigned char* string) {
	//puts("\nHi\nOlaa!\n");
	unsigned int scancode = 0;
	unsigned int pressed = 0;
	
	puts("\nWhich process would you like to run?\n");
	puts("1 : proc1\n");
	puts("2 : proc2\n");
	puts("3 : proc3\n");
	puts("4 : testprogram\n");
	
	__asm__ __volatile__ ("cli");
	
	//unsigned int oldkey = inportb(0x60);
	
	//while((inportb(0x64) & 0x80) == 1) {}
	//while((inportb(0x60)&80)) {}
	
	do {
		scancode = inportb(0x60);
		printInt(scancode);
		delay(1000);
	} while(scancode != 156);
	
	do {
		//inportb(0x64);
		//outportb(0x64, 60);
		printInt(inportb(0x60));
		scancode = inportb(0x60);
		//printInt(scancode);
		if(kbdus[scancode] != 0)
			pressed = 1;
			
	} while(pressed != 1);
	
	
	while(kbdus[scancode] == 0) {
		scancode = inportb(0x60);
	} 
	
	
	switch(kbdus[scancode]) {
		
		case '1' :
			puts("Pressed 1\n");
			break;
	
		case '2' :
		 
			break;
	
		case '3' :
		 
			break;
		
		case '4' :
		 
			break;
		
	}
	
	__asm__ __volatile__ ("sti");
	
	putch('\n');
	
	si = 0;
	clearstring();
}
*/
