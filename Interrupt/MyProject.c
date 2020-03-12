#include "interrupt.h"

void interrupt( void );
void main() {


  TRISC_REG.Register = 0;
interrupt_init();
         LED1 = 0;
      while( 1 ) 
      {
             LED0  = 0;
              Delay_ms(100);
              LED0 = 1;
                Delay_ms(100);
       }



}
