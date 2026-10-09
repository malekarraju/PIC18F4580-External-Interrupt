#include <p18f4580.h>
#define Led PORTCbits.RC2 

void T0_delay(unsigned int);

void main(void)
{
	TRISCbits.RC2 = 0;

	//Timer Init
	T0CON = 0X07;//16 BIT,TIMER OFF,1:25

	// a TO d CONVERSION
	ADCON1 = 0x0F;

	RCONbits.IPEN = 0;  // Interrupt Level Disable (setting manually interrupt level)
	INTCONbits.GIE = 1; // Global(Hardware) Interrupt Active
	INTCONbits.PEIE = 0; // disable all peripheral(software) interrupt 

	INTCON3bits.INT1IE = 1; // Enable INT1 from INTCON3 register

	INTCON2bits.INTEDG1 = 0; // Falling edge selection of INT1 from register INTCON2
	
	Led = 0;
	
	while(1)
	{
	}
}

#pragma code Ext_Intr1 = 0x08   // 0x08 High priority & 0x18 Low priority
#pragma interrupt Ext_Intr1

void Ext_Intr1(void)
{
	Led = 1;
	T0_delay(1000); // in milli second 
	
	Led = 0;
	T0_delay(1000);
	
	INTCON3bits.INT1IF = 0;
}

void T0_delay(unsigned int Tdesired)
{
	long int preload = 65535 - (Tdesired/0.256);

	TMR0H = preload >> 8;
	TMR0L = preload & 0xFF;

	T0CONbits.TMR0ON = 1;//TIMER START

	while(INTCONbits.TMR0IF==0);//wait for interrupt overload
	INTCONbits.TMR0IF=0;//CLAER THE FLAG BIT

	T0CONbits.TMR0ON = 0;//STOP TIMER
}