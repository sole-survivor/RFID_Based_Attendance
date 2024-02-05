#include<lpc21xx.h>
#include"header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR ((U0LSR&1))
void uart0_init(void)
{
	PINSEL0|=0X5;
	U0LCR=0X83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0X03;
}

void uart0_tx (unsigned char data)
{
	U0THR=data;
	while(THRE==0);
}

void uart0_string_tx (char*p)
{
	while (*p)
	{
		uart0_tx(*p);
		p++;
	}
}

signed char  uart0_rx (void)
{
	while (RDR==0);
	return U0RBR;
}

void uart0_string_rx (char*ptr,int max)
{
	int i;
	for (i=0;i<max;i++)
	{
		ptr[i]=uart0_rx();
		if(ptr[i]=='\r')
			break;
	}
	ptr[i]='\0';
}

void rfid_rx (char*ptr,int max)
{
	int i;
	for (i=0;i<max;i++)
	{
		ptr[i]=uart0_rx();
	}
}
