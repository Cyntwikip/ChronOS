//Interface
void delay(unsigned int timedelay);
void print(char str[]);
void printchar(char c);
void printc(char str[], unsigned int color);
void printindex(char str[], unsigned int i, unsigned int color);
void clearscreen(void);
void backspace(void);
void caret (int i);

//from Internet!!!
void move_csr(void);
unsigned char inportb (unsigned short _port);
void outportb (unsigned short _port, unsigned char _data);



#define tabspace 10


//initialize //USE static!
static char *vidptr = (char*)0xb8000; 	//video mem begins here.
static unsigned int index=0;


//functions

void delay(unsigned int timedelay) {
	int i;
	int j;
	int c;
	
	for(i=0; i<timedelay; i++) {
		for(j=0; j<timedelay; j++)
			c = i*j;
		}
	
}

//generic print function
void print(char str[]) {
	unsigned int j = 0;
	
	index = index%4000; //so that it will not go out of bounds!
	
	while(str[j] != '\0') {
		//0x5c is '\'
		//0xA is newline
		if(str[j] == 0xA) {
			index/=160;
			index++;
			index*=160;//goes to next row...
		}
		else if(str[j] == '\t') {
			index/=tabspace*2;
			index*=tabspace*2;
			index+=tabspace*2;
		}
		else {
			vidptr[index] = str[j];
			vidptr[index+1] = 0x07;
			index = index + 2;
		}
		index = index%4000; //so that it will not go out of bounds!
		++j;
	}
}

void printchar(char c) {
	
	index = index%4000; //so that it will not go out of bounds!
	
	if(c == '\b') 
		backspace();
	else if(c == '\n') {
		index/=160;
		index++;
		index*=160;//goes to next row...
	}
	else if(c == '\t') {
		index/=tabspace*2;
		index*=tabspace*2;
		index+=tabspace*2;
	}	
	else {
		vidptr[index] = c;
		vidptr[index+1] = 0x07;
		index = index + 2;
	}
	
	index = index%4000; //so that it will not go out of bounds!
	caret(index/2);
}

//print with color
void printc(char str[], unsigned int color) {
	unsigned int j = 0;
	
	index = index%4000; //so that it will not go out of bounds!
	
	while(str[j] != '\0') {
		//0x5c is '\'
		//0xA is newline
		if(str[j] == 0xA) {
			index/=160;
			index++;
			index*=160;//goes to next row...
		}
		else if(str[j] == '\t') {
			index/=tabspace*2;
			index*=tabspace*2;
			index+=tabspace*2;
		}
		else {
			vidptr[index] = str[j];
			vidptr[index+1] = color;
			index = index + 2;
		}
		index = index%4000; //so that it will not go out of bounds!
		++j;
	}
}

//print with color and set which index will it print onto
void printindex(char str[], unsigned int i, unsigned int color) {
	unsigned int j = 0;
	
	i = i%4000; //so that it will not go out of bounds!
	
	while(str[j] != '\0') {
		//0x5c is '\'
		//0xA is newline
		if(str[j] == 0xA) {
			i/=160;
			i++;
			i*=160;//goes to next row...
		}
		else if(str[j] == '\t') {
			i/=tabspace*2;
			i*=tabspace*2;
			i+=tabspace*2;
		}		
		//just skips if space
		else if(str[j] == ' ') {
			i = i + 2;
		}
		else {
			vidptr[i] = str[j];
			vidptr[i+1] = color;
			i = i + 2;
		}
		i = i%4000; //so that it will not go out of bounds!
		++j;
	}
	
	//just to display the caret (blinking line) after text :)
	//int z = i/160;
	//z*=80;
	//i%=160;
	//i = i+z;
	//i = 1998;
	caret(i/2);
}

void backspace(void) {
	index -= 2;
	if(index<0)
		index = 0;
		
	vidptr[index] = ' ';	
	vidptr[index+1] = 0x07;
}

void clearscreen(void) {

	unsigned int i = 0;
	unsigned int j = 0;
	//clear all
	while(j < 80 * 25 * 2) {
		//blank character
		vidptr[j] = ' ';
		//attribute-byte: light grey on black screen	
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}

}

void caret(int i)
{
    unsigned temp;

    temp = i;

    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}




