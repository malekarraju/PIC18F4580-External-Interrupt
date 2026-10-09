#include <p18f4580.h>
#define Led PORTCbits.RC1

void main(void)
{
	TRISCbits.RC1 = 0;
	
	// Interrupt
	ADCON1 =0x0F;
	
	RCONbits.IPEN = 0; // disable auto interrupt priority
	INTCONbits.GIE = 1; // active all global (hardware) interrupt 
	INTCONbits.PEIE = 0; // disactive all peripheral (software) interrupt
	
	INTCON3bits.INT2IE = 1; // enable INT2 piin by INTCON3 register
	
	INTCON2bits.INTEDG2 = 0; // set falling	edge of pin INT2 by INTCON2 register
	
	Led = 0;

	while(1)
	{
	}
}


#pragma code Ext_Intr2 = 0x08 // 0x08 high, 0x18 low
#pragma interrupt Ext_Intr2
 
void Ext_Intr2(void)
{
 	Led = ~Led; // Toggle Led

	INTCON3bits.INT2IF = 0; // clear the INT2 flag by INTCON3 register
}
