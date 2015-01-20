#include "system.h"

/*
void moving_string() {
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	int max = 80*2;
	int i, j, k, l;
		
	k=0;
	
	for(j=0; j<=max; j+=2) {
		//if(temp_struct.csr_x*2 > j) {
			for(l=0; l<m_struct[0].csr_x*2; l+=2)	{
				vidptr[(m_struct[0].csr_y)*160+l] = ' ';
				vidptr[(m_struct[0].csr_y)*160+l+1] = 0x03; //attrib = color
			}
		//}
		//else {
			while(m_struct[0].m_str[k]!='\0' && j+k*2 < max) {
				vidptr[(m_struct[0].csr_y)*max+k*2+j] = m_struct[0].m_str[k];
				vidptr[(m_struct[0].csr_y)*max+k*2+1+j] = 0x0E;
				k++;
			}
			m_struct[0].csr_x++;
			k=0;
		//}
		//timer_wait(18);
		delay(1000);
	}

}
*/


void moving_string() {
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	int max = 80*2;
	int i, j, k, l;
		
	k=0;
	i=0;
	
	for(i=0; i<last_data_index; i++) {
		/*
		for(j=0; j<max; j+=2) {
			vidptr[(m_struct[i].csr_y)*160+j] = ' ';
			vidptr[(m_struct[i].csr_y)*160+j+1] = 0x0E; //attrib = color			
		}
		*/
		for(j=0; j<=max; j+=2) {
						
			for(l=0; l<=m_struct[i].csr_x*2; l+=2)	{
				vidptr[(m_struct[i].csr_y)*160+l] = ' ';
				vidptr[(m_struct[i].csr_y)*160+l+1] = 0x0E; //attrib = color
			}
			
			j = l;
			
			while(m_struct[i].m_str[k]!='\0' && j+k*2 < max) {
				vidptr[(m_struct[i].csr_y)*max+k*2+j] = m_struct[i].m_str[k];
				vidptr[(m_struct[i].csr_y)*max+k*2+1+j] = 0x0E;
				k++;
			}
			
			if(j+k*2 >= max) {
				vidptr[(m_struct[i].csr_y)*max+k*2+j-2] = ' ';
				vidptr[(m_struct[i].csr_y)*max+k*2+1+j-2] = 0x0E;
			}
				
			
			j = max+2;
			
			m_struct[i].csr_x++;
			if(m_struct[i].csr_x == 80)
				m_struct[i].csr_x = 0;
				
			k=0;
			//timer_wait(1);
			//delay(1000);
		}
	}

}

