#line 1 "C:/Users/Sayed/Desktop/G50_2/Seven_Seg_Lec/Seven_Seg_Lec/Test2/Seven_Seg1.c"
#line 1 "c:/users/sayed/desktop/g50_2/seven_seg_lec/seven_seg_lec/test2/seven_seg_driver.h"
#line 1 "c:/users/sayed/desktop/g50_2/seven_seg_lec/seven_seg_lec/test2/reg.h"
#line 13 "c:/users/sayed/desktop/g50_2/seven_seg_lec/seven_seg_lec/test2/reg.h"
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

typedef union{
 uint8_t Register;
 struct{
 uint8_t Bit0 : 1;
 uint8_t Bit1 : 1;
 uint8_t Bit2 : 1;
 uint8_t Bit3 : 1;
 uint8_t Bit4 : 1;
 uint8_t Bit5 : 1;
 uint8_t Bit6 : 1;
 uint8_t Bit7 : 1;
 }Register_Bits;
}Register_t;
#line 7 "c:/users/sayed/desktop/g50_2/seven_seg_lec/seven_seg_lec/test2/seven_seg_driver.h"
extern uint8_t seven_seg_values[10];
#line 20 "c:/users/sayed/desktop/g50_2/seven_seg_lec/seven_seg_lec/test2/seven_seg_driver.h"
typedef enum{
 PORTA_R,
 PORTB_R,
 PORTC_R,
 PORTD_R
}Register_Name_t;

void seven_segment_print_port_nuumber_init(Register_Name_t port);
void seven_segment_print_port_nuumber(Register_Name_t port, uint8_t number);
uint8_t convert_number_seven_segement(uint8_t number);
#line 4 "C:/Users/Sayed/Desktop/G50_2/Seven_Seg_Lec/Seven_Seg_Lec/Test2/Seven_Seg1.c"
uint8_t counter = 0;

void main() {
  (*((volatile Register_t *)0xF95)) .Register_Bits.Bit1=0;
  (*((volatile Register_t *)0xF83)) .Register_Bits.Bit1=0;
 seven_segment_print_port_nuumber_init(PORTC_R);
 while(1){
 if ( (*((volatile Register_t *)0xF83)) .Register_Bits.Bit1==1){
 for(counter=0; counter<100; counter++){
 seven_segment_print_port_nuumber(PORTC_R, convert_number_seven_segement(counter));
 Delay_ms(250);
 }
 }
}
}
