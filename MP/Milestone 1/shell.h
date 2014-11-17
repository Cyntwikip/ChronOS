
#include "system.h";
#include "library.h";
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
	unsigned int Cyan = 0x03;
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

