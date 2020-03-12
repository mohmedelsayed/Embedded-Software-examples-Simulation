#line 1 "C:/Users/Sayed/Desktop/Embedded Tests/interrupt.c"
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
#line 4 "C:/Users/Sayed/Desktop/Embedded Tests/interrupt.c"
void interrupt_init( void ){
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit1 =0 ;
  (*((volatile Register_t *)0xF93)) .Register_Bits.Bit0 = 1 ;
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit7 =1 ;
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit6 =1 ;
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit4 =1 ;
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit3 =1 ;
  (*((volatile Register_t *)0xFF1)) .Register_Bits.Bit6 =0 ;
 RBIF_bit = 0;

 }

void interrupt( void )
{
 if (  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit1 ==1 )
 {
  (*((volatile Register_t *)0xFF2)) .Register_Bits.Bit1 =0;
  (*((volatile Register_t *)0xF82)) .Register_Bits.Bit4  = ~  (*((volatile Register_t *)0xF82)) .Register_Bits.Bit4  ;

 }
 if(RBIF_bit == 1 && RB4_bit == 1){
 RBIF_bit = 0;
 RC4_bit = 1;
 }
 else if(RBIF_bit == 1 && RB4_bit == 0){
 RBIF_bit = 0;
 RC4_bit = 0;
 }

 if(RBIF_bit == 1 && RB5_bit == 1){
 RBIF_bit = 0;
 RC4_bit = 1;
 }
 else if(RBIF_bit == 1 && RB5_bit == 0){
 RBIF_bit = 0;
 RC4_bit = 0;
 }

 if(RBIF_bit == 1 && RB6_bit == 1){
 RBIF_bit = 0;
 RC4_bit = 1;
 }
 else if(RBIF_bit == 1 && RB6_bit == 0){
 RBIF_bit = 0;
 RC4_bit = 0;
 }
}
