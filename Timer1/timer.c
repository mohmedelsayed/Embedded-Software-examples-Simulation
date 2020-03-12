#include "timer.h"
   uint8_t overFlowsCounter = 0 ;
void timer1_init(void)
{
 TMR1IF_bit = 0;
  TMR1H         = 0x0B;
  TMR1L         = 0xDC;

 INTCON_REG.Register_Bits.Bit6 = 1;   //PEIE
 INTCON_REG.Register_Bits.Bit7 = 1;   //GIEH
 PIE1_REG.Register_Bits.Bit0   = 1;    //TMR1IE
 T1CON_REG.Register_Bits.Bit0  = 0;   //TMR1ON
 T1CON_REG.Register_Bits.Bit1  = 0;   //TMR1CS
 T1CON_REG.Register_Bits.Bit4  = 1;   //T1CKPS0
 T1CON_REG.Register_Bits.Bit5  = 1;   //T1CKPS1


}
void interrupt (void)
{
     if ( TMR1IF_bit)

     {

        TMR1H         = 0x0B;
        TMR1L         = 0xDC;
        overFlowsCounter++ ;
        if ( overFlowsCounter == 2)
        {

        RC0_bit = ~ RC0_Bit;
        overFlowsCounter=0;
        }

        TMR1IF_bit =   0 ;



     }

}

void timer1_on (void)
{
  T1CON_REG.Register_Bits.Bit0 = 1;   //TMR1ON

}
void timer1_off(void)
{
  T1CON_REG.Register_Bits.Bit0 = 0;   //TMR1ON
}