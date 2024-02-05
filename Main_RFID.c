#include<lpc21xx.h>
#include<string.h>
#include"header.h"
int main()
{
	int i,f=0;
	char arr[8];
	char p[][9]={"ABCDEFGH\0","IJKLMNOP\0","QRSTUVWX\0"};
	char n[][20]={"KARNAN\0","NAPOLEON\0","BHAGATH SINGH\0"};
	uart0_init(); 
	lcd_init();
	lcd_cmd(0x01);
	uart0_string_tx("RFID ATTENDENCE\r\n");
	lcd_string("RFID ATTENDENCE\r\n");
	while(1)
	{
		rfid_rx(arr,8);
		uart0_string_tx("ID: ");
		uart0_string_tx(arr);
		uart0_string_tx("\r\n");
		i=0;
		while (i<3)
		{
			if((strcmp(arr,p[i])==0))
			{
				lcd_cmd(0x01);
				uart0_string_tx("Welcome!\r\n");
				uart0_string_tx(n[i]);
				uart0_string_tx("\r\n");
				lcd_string("Welcome!\r\n");
				lcd_cmd(0xc0);
				lcd_string(n[i]);
				f=1;
				break;
			}
			else{
				i++;
			}
		}
		if (f==0)
		{
				lcd_cmd(0x01);
				uart0_string_tx("User Not Found!");
				uart0_string_tx("\r\n");
				lcd_string("User Not Found!");
		}
		else
			{
				f=0;
			}
		}
	}
