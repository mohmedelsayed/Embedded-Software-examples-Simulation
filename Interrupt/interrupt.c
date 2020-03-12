#include "interrupt.h"


void interrupt_init( void ){
   INTCON_REG.Register_Bits.Bit1 =0 ; // The INT0 external interrupt did not occur
   TRISB_REG.Register_Bits.Bit0 = 1 ; // Make int0_Bit Input
   INTCON_REG.Register_Bits.Bit7 =1 ; // important for Enables interrupts
   INTCON_REG.Register_Bits.Bit6 =1 ; // important for Enables interrupts
   INTCON_REG.Register_Bits.Bit4 =1 ; // Enables the INT0 external interrupt
   INTCON_REG.Register_Bits.Bit3 =1 ; // Enables the RB port change interrupt
   INTCON2_REG.Register_Bits.Bit6 =0 ; // Interrupt on Falling edge
   RBIF_bit = 0;
                                      //
  }                                    //

void interrupt( void )
{
    if ( INTCON_REG.Register_Bits.Bit1 ==1 )
    {
       INTCON_REG.Register_Bits.Bit1 =0;
       LED1 = ~ LED1 ;

    }
      if(RBIF_bit == 1 && RB4_bit == 1){
       RBIF_bit = 0;
       RC4_bit = 1;
    }
    else if(RBIF_bit == 1 && RB4_bit == 0){
       RBIF_bit = 0;
       RC4_bit = 0;
    }
    // ------------------------------------
    if(RBIF_bit == 1 && RB5_bit == 1){
       RBIF_bit = 0;
       RC4_bit = 1;
    }
    else if(RBIF_bit == 1 && RB5_bit == 0){
       RBIF_bit = 0;
       RC4_bit = 0;
    }
    // ------------------------------------
    if(RBIF_bit == 1 && RB6_bit == 1){
       RBIF_bit = 0;
       RC4_bit = 1;
    }
    else if(RBIF_bit == 1 && RB6_bit == 0){
       RBIF_bit = 0;
       RC4_bit = 0;
    }
}