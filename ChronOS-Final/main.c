/* bkerndev - Bran's Kernel Development Tutorial
*  By:   Brandon F. (friesenb@gmail.com)
*  Desc: Main.c: C code entry.
*
*  Notes: No warranty expressed or implied. Use at own risk. */
//#include <system.h>
/*
#include "gdt.c"
#include "idt.c"
#include "isrs.c"
#include "irq.c"
#include "scrn.c"
#include "timer.c"
#include "kb.c"
//#include "shell.h"
#include "marquee.c";
#include "globals.c"
*/

#include "system.h";

void *memcpy(void *dest, const void *src, size_t count)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

void *memset(void *dest, char val, size_t count)
{
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count)
{
    unsigned short *temp = (unsigned short *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

size_t strlen(const char *str)
{
    size_t retval;
    for(retval = 0; *str != '\0'; str++) retval++;
    return retval;
}

unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void main()
{
    int i;

    gdt_install();
    idt_install();
    isrs_install();
    irq_install();
    init_video();
    timer_install();
    keyboard_install();

    __asm__ __volatile__ ("sti");
    
    /*
    base_data_index = 0;
    last_data_index = 0;
    marquee_flag = 0;
    si = 0;
	*/

	//_sys_stack = (int*) _sys_stack + 1;
	
    displayOS();
     
     
    cs_init();

    while(1) {		
	
		//putch(getch());
		//timer_wait(6);
		//printInt(_sys_stack);
		//printInt(*_sys_stack);
		//printInt(*(_sys_stack+1));
		//delay(10000);
	
	}
    

//    i = 10 / 0;
//    putch(i);

    //for (;;);
}
