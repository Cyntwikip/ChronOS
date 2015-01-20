/* bkerndev - Bran's Kernel Development Tutorial
*  By:   Brandon F. (friesenb@gmail.com)
*  Desc: Global function declarations and type definitions
*
*  Notes: No warranty expressed or implied. Use at own risk. */
#ifndef __SYSTEM_H
#define __SYSTEM_H

typedef int size_t;

/* This defines what the stack looks like after an ISR was running */
struct regs
{
	unsigned int targetesp;		//for context switch?
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;    
};

extern unsigned int *_sys_stack();

/* MAIN.C */
extern void *memcpy(void *dest, const void *src, size_t count);
extern void *memset(void *dest, char val, size_t count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count);
extern size_t strlen(const char *str);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);

/* CONSOLE.C */
extern void init_video(void);
extern void puts(unsigned char *text);
extern void putch(unsigned char c);
extern void cls();
extern int csr_y, csr_x, attrib;

/* GDT.C */
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
extern void gdt_install();

/* IDT.C */
extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
extern void idt_install();

/* ISRS.C */
extern void isrs_install();

/* IRQ.C */
extern void irq_install_handler(int irq, void (*handler)(struct regs *r));
extern void irq_uninstall_handler(int irq);
extern void irq_install();

/* TIMER.C */
extern void timer_wait(int ticks);
extern void timer_install();

/* KEYBOARD.C */
extern unsigned char kbdus[128];
extern void keyboard_install();

/* MARQUEE.C */
//extern void marq();
extern void marquee();
extern void moving_text();

typedef struct {

	unsigned char m_str[50];
	int csr_y;
	int csr_x;	

} data;

/* GLOBALS.C */
//extern typedef struct data;
extern data m_struct[50];
extern data temp_struct;
extern unsigned int base_data_index;
extern unsigned int last_data_index;
extern unsigned int marquee_flag;
extern unsigned int mi;

extern unsigned int si;

/* MOVINGSTRING.C */
extern void moving_string();

/* CS.C */

//Milestone 1
extern void cs_init();
extern void cs(struct regs *r);
extern void exitp();
extern char getch();
extern char* gets();
extern int getInt(char* num);
extern void printInt(int num);


typedef struct {
	unsigned int targetesp;	//pointer to the interrupt frame
	unsigned int esp;
	unsigned int ebp;		
	unsigned int eip;		//specific line of code in the process
	unsigned int isInit; 	//1 if initialized; 0 if not
	unsigned int *stack;	//stack's location in memory
	unsigned int active;
} process;

extern process processes[20];
extern int p_curr;
extern int p_limit;


/* MEMORY.C */

typedef struct {
	unsigned int *base;		//base of malloc stack
	unsigned int *top;		//top of malloc stack
	unsigned int isActive;	//1 if active; 0 if not
} mallocdata;

extern mallocdata mallocstack[100];
extern unsigned int mallocstackindex;
extern unsigned int m_limit;

extern unsigned int* malloc(unsigned int size);
extern unsigned int freealloc(unsigned int *base);
extern void rand1();

/* PROCESS.C */
extern void func1();
extern void func2();
extern void func3();
extern void testprogram();


#endif
