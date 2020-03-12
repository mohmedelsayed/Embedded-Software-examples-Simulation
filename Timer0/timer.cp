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
 void timer0_init(void);
 void interrupt (void);
 void timer0_on (void);
 void timer0_off(void);
#line 2 "C:/Users/Sayed/Desktop/Embedded Tests/Timer0/timer.c"
 uint8_t overFlowsCounter = 0 ;
void timer0_init(void)
{
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit2 = 0;
 TMR0L = 0xDC;
 TMR0H = 0x0B;
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit6 = 1;
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit7 = 1;
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit5 = 1;
  (*((volatile Register_t *)0xFD5)) .Register_Bits.Bit7 = 0;
  (*((volatile Register_t *)0xFD5)) .Register_Bits.Bit6 = 0;
  (*((volatile Register_t *)0xFD5)) .Register_Bits.Bit5 = 0;
  (*((volatile Register_t *)0xFD5)) .Register_Bits.Bit4 = 0;
  (*((volatile Register_t *)0xFD5)) .Register_Bits.Bit3 = 0;
  (*((volatile Register_t *)0xFD5)) .Register_Bits.Bit2 = 0;
  (*((volatile Register_t *)0xFD5)) .Register_Bits.Bit1 = 1;
  (*((volatile Register_t *)0xFD5)) .Register_Bits.Bit0 = 1;






}
void interrupt (void)
{
 if (  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit2)

 { RC0_bit = ~ RC0_Bit;
 TMR0L = 0xDC;
 TMR0H = 0x0B;

  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit2 = 0 ;
 }

}

void timer0_on (void)
{
  (*((volatile Register_t *)0xFD5)) .Register_Bits.Bit7 = 1;

}
void timer0_off(void)
{
  (*((volatile Register_t *)0xFD5)) .Register_Bits.Bit7 = 0;
}
