#line 1 "C:/Users/Sayed/Desktop/Embedded Tests/Timer0/Timer1.c"
#line 1 "c:/users/sayed/desktop/embedded tests/timer0/timer.h"
#line 1 "c:/users/sayed/desktop/embedded tests/timer0/reg.h"



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
 struct{
 uint8_t nipple0 : 4;
 uint8_t nipple1 : 4;
 }nipples;
}Register_t;
#line 7 "c:/users/sayed/desktop/embedded tests/timer0/timer.h"
 void timer1_init(void);
 void interrupt (void);
 void timer1_on (void);
 void timer1_off(void);
#line 3 "C:/Users/Sayed/Desktop/Embedded Tests/Timer0/Timer1.c"
void main() {
  (*((volatile Register_t *)0xF94)) .Register = 0;
 RC0_bit = 0;
 timer1_init();
 timer1_on();
}
