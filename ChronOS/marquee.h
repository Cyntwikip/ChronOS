
void marquee(void);

static unsigned char *string;

typedef struct {

	unsigned char *m_str;
	int csr_y;
	int csr_x;	

} data;
/*
 data *m_struct;
 data temp_struct;
//static data m_struct;
 unsigned int base_data_index = 0;
 unsigned int last_data_index = 0;
*/
void marquee() {
	
	m_struct = &temp_struct;
	
	m_struct->csr_x = 8;
	
	//*(m_struct+0)->m_str = 8;
	//m_struct->m_str = 8;
	//temp_struct = m_struct+0;
	//temp_struct.m_str[0]=8;
	
	//if(m_struct->m_str == 8)
	//if(*(m_struct+0)->m_str == 8)
	//if(*(m_struct+0)->m_str == *(m_struct+0)->m_str)
	if(m_struct->csr_x == 8)
		puts("Working!!!");
}

/*
void marquee() {
	
	int max = 80*2;
	int i, j, k;
	data temp_struct;
	
	for(i=0; i<=last_data_index; i++) {
		temp_struct = *(m_struct+i);
		
		k=0;
		
		//for(j=temp_struct.csr_x; j<max; j+=2) {
		for(j=0; j<max; j+=2) {
			if(temp_struct.csr_x < j) {
				vidptr[(temp_struct.csr_y)*160+csr_x] = ' ';
				vidptr[(temp_struct.csr_y)*160+csr_x+1] = attrib; //attrib = color
			}
			else {
				if(temp_struct.m_str[k] == '\0')
					vidptr[(temp_struct.csr_y)*160+csr_x+k] = ' ';
				else
					vidptr[(temp_struct.csr_y)*160+csr_x+k] = temp_struct.m_str[k];
				vidptr[(temp_struct.csr_y)*160+csr_x+1+k] = attrib; 
				k++;
			}
			
		}		
		
	}
	
	//puts("Hello World!!");
	//putch('\n');	
	
}
*/

