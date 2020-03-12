#line 1 "C:/Users/Sayed/Desktop/Embedded Tests/Timer0/timer.c"
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
#line 2 "C:/Users/Sayed/Desktop/Embedded Tests/Timer0/timer.c"
 uint8_t overFlowsCounter = 0 ;
void timer1_init(void)
{
 TMR1IF_bit = 0;
 TMR1H = 0x0B;
 TMR1L = 0xDC;

  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit6 = 1;
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit7 = 1;
  (*((volatile Register_t *)0xF9D)) .Register_Bits.Bit0 = 1;
  (*((volatile Register_t *)0xFCD)) .Register_Bits.Bit0 = 0;
  (*((volatile Register_t *)0xFCD)) .Register_Bits.Bit1 = 0;
  (*((volatile Register_t *)0xFCD)) .Register_Bits.Bit4 = 1;
  (*((volatile Register_t *)0xFCD)) .Register_Bits.Bit5 = 1;


}
void interrupt (void)
{
 if ( TMR1IF_bit)

 {

 TMR1H = 0x0B;
 TMR1L = 0xDC;
 overFlowsCounter++ ;
 if ( overFlowsCounter == 2)
 {

 RC0_bit = ~ RC0_Bit;
 overFlowsCounter=0;
 }

 TMR1IF_bit = 0 ;



 }

}

void timer1_on (void)
{
  (*((volatile Register_t *)0xFCD)) .Register_Bits.Bit0 = 1;

}
void timer1_off(void)
{
  (*((volatile Register_t *)0xFCD)) .Register_Bits.Bit0 = 0;
}
