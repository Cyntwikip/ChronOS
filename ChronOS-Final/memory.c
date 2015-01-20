
#include "system.h"

//unsigned int frealloc(unsigned int *base);

mallocdata mallocstack[100];
unsigned int mallocstackindex=0;
unsigned int m_limit = 100;

//unsigned int *currLoc = _sys_stack + 1;
unsigned int *currLoc = 0x00106000;
//unsigned int *currLoc = 88000;

unsigned int* malloc(unsigned int size) {
	
	unsigned int *memloc = 0;
	
	memloc = currLoc;	
	mallocstack[mallocstackindex].base = currLoc;	
	//currLoc = currLoc+(((currLoc+size)-currLoc)/4);		//HAHAHAH!!!
	currLoc = currLoc + size;
	mallocstack[mallocstackindex].top = currLoc;
	mallocstack[mallocstackindex].isActive = 1;
	
	mallocstackindex++;	
	
	return memloc; 
}


unsigned int freealloc(unsigned int *base) {

	unsigned int i;
	unsigned int *temp;
	unsigned int success = 0; 	
 	
	//searches the mallocdata structure
	for(i=0; i<m_limit; i++) {
		if(mallocstack[i].base == base) {
			//puts("Inside lalaa");
			//timer_wait(90);
			//delay(10000);
			temp = mallocstack[i].base;
			while(temp!=mallocstack[i].top) {
				//printInt(temp);
				//timer_wait(18);
				*temp = '\0';
				temp = temp+1;
			}
			mallocstack[i].isActive = 0;			
			success = 1;
		}
	}
	 
	return success;
}

void rand1() {
	puts("OLAAA!");
	puts("OLAAA!");
	puts("OLAAA!");
	puts("OLAAA!");
}


