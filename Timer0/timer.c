#include "timer.h"
   uint8_t overFlowsCounter = 0 ;
void timer0_init(void)
{
 INTCON_REG.Register_Bits.Bit2 = 0;    //TMR0 Overflow Interrupt Flag bit
  TMR0L	 = 0xDC;
  TMR0H	 = 0x0B;
 INTCON_REG.Register_Bits.Bit6 = 1;   //PEIE
 INTCON_REG.Register_Bits.Bit7 = 1;   //GIEH
 INTCON_REG.Register_Bits.Bit5 = 1;   //TMR0 Overflow Interrupt Enable bit
 T0CON_REG.Register_Bits.Bit7  = 0;    //Timer0 On/Off Control bit
 T0CON_REG.Register_Bits.Bit6  = 0;    //Timer0 8-Bit/16-Bit Control bit
 T0CON_REG.Register_Bits.Bit5  = 0;    //Timer0 Clock Source Select bit
 T0CON_REG.Register_Bits.Bit4  = 0;    //Timer0 Source Edge Select bit
 T0CON_REG.Register_Bits.Bit3  = 0;    //Timer0 Prescaler Assignment bit
 T0CON_REG.Register_Bits.Bit2  = 0;    //Timer0 Prescaler Select bits
 T0CON_REG.Register_Bits.Bit1  = 1;    //Timer0 Prescaler Select bits
 T0CON_REG.Register_Bits.Bit0  = 1;    //Timer0 Prescaler Select bits
 
 
 
 


}
void interrupt (void)
{
     if ( INTCON_REG.Register_Bits.Bit2)

     {  RC0_bit = ~ RC0_Bit;
        TMR0L	 = 0xDC;
        TMR0H	 = 0x0B;

        INTCON_REG.Register_Bits.Bit2 =   0 ;
     }

}

void timer0_on (void)
{
  T0CON_REG.Register_Bits.Bit7 = 1;   //TMR1ON

}
void timer0_off(void)
{
  T0CON_REG.Register_Bits.Bit7 = 0;   //TMR1ON
}