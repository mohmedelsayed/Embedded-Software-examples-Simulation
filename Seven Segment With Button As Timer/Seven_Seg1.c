/*
````````````````````````````````````````````````````````````````````````````````
`  * File                        => Seven_Seg1.c                           `   `
`  * Information                 => This Is Example to Learn about 7segments   `
`  * Author                      => Mohmed Elsayed Abd Ellatef .       `       `
`  * Date                        => 28-Feb-2019                                `
````````````````````````````````````````````````````````````````````````````````
*/
#include "seven_seg_driver.h"

uint8_t counter = 0;

void main() {
     TRISD_REG.Register_Bits.Bit1=0;
     PORTD_REG.Register_Bits.Bit1=0;
    seven_segment_print_port_nuumber_init(PORTC_R);
    while(1){
    if (PORTD_REG.Register_Bits.Bit1==1){
       for(counter=0; counter<100; counter++){
          seven_segment_print_port_nuumber(PORTC_R, convert_number_seven_segement(counter));
          Delay_ms(250);
       }
    }
}
}