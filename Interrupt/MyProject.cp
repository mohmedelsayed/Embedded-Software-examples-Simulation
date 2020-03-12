#line 1 "C:/Users/Sayed/Desktop/Embedded Tests/MyProject.c"
#line 1 "c:/users/sayed/desktop/embedded tests/interrupt.h"
#line 1 "c:/users/sayed/desktop/embedded tests/reg.h"



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
#line 8 "c:/users/sayed/desktop/embedded tests/interrupt.h"
typedef enum{

 PRIORITY_ENABLE,
 PRIORITY_DISABLE

}priority_state;

typedef enum{

 HIGH_PRIORITY,
 LOW_PRIORITY

}interrupt_Type;








void interrupt_init( void );
void interrupt(void);
#line 3 "C:/Users/Sayed/Desktop/Embedded Tests/MyProject.c"
void interrupt( void );
void main() {


  (*((volatile Register_t *)0xF94)) .Register = 0;
interrupt_init();
  (*((volatile Register_t *)0xF82)) .Register_Bits.Bit4  = 0;
 while( 1 )
 {
  (*((volatile Register_t *)0xF82)) .Register_Bits.Bit0  = 0;
 Delay_ms(100);
  (*((volatile Register_t *)0xF82)) .Register_Bits.Bit0  = 1;
 Delay_ms(100);
 }



}
