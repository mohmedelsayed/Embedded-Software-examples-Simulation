#line 1 "E:/ÇáßæÑÓÇÊ/Embdade System Deploma/My Works/4bit_mode_with_shifting_words/lcd_d.c"
#line 1 "e:/ÇáßæÑÓÇÊ/embdade system deploma/my works/4bit_mode_with_shifting_words/reg.h"
#line 13 "e:/ÇáßæÑÓÇÊ/embdade system deploma/my works/4bit_mode_with_shifting_words/reg.h"
typedef unsigned char uint8_t;
typedef unsigned short uint4_t;
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
#line 11 "E:/ÇáßæÑÓÇÊ/Embdade System Deploma/My Works/4bit_mode_with_shifting_words/lcd_d.c"
 void lcd_init();
 void toggle();
 void lcd_cmd_hf(char v1);
 void lcd_cmd(char v2);
 void lcd_dwr(char v3);
 void lcd_msg(char *c);
 void delay(int ms);
 void lcd_lef_sh();
 void lcd_rig_sh();



 void main()
 {
  (*((volatile Register_t *)0xF94)) .Register  = 0x00;
 lcd_init();
 while(1){
 lcd_cmd(0x96);
 lcd_msg(" Sayed Super-Market");
 lcd_lef_sh();
#line 47 "E:/ÇáßæÑÓÇÊ/Embdade System Deploma/My Works/4bit_mode_with_shifting_words/lcd_d.c"
 }

 }


 void toggle()
 {
  (*((volatile Register_t *)0xF82)) .Register_Bits.Bit1  = 1;
 delay(1);
  (*((volatile Register_t *)0xF82)) .Register_Bits.Bit1  = 0;
 }

 void lcd_cmd_hf(char v1)
 {
  (*((volatile Register_t *)0xF82)) .Register_Bits.Bit0  = 0;
  (*((volatile Register_t *)0xF82)) .Register  &= 0x0F;
  (*((volatile Register_t *)0xF82)) .Register  |= (v1 & 0xF0);
 toggle();
 }

 void lcd_cmd(char v2)
 {
  (*((volatile Register_t *)0xF82)) .Register_Bits.Bit0  = 0;
  (*((volatile Register_t *)0xF82)) .Register  &= 0x0F;
  (*((volatile Register_t *)0xF82)) .Register  |= (v2 & 0xF0);
 toggle();

  (*((volatile Register_t *)0xF82)) .Register  &= 0x0F;
  (*((volatile Register_t *)0xF82)) .Register  |= ((v2 & 0x0F)<<4);
 toggle();
 }

 void lcd_dwr(char v3)
 {
  (*((volatile Register_t *)0xF82)) .Register_Bits.Bit0  = 1;
  (*((volatile Register_t *)0xF82)) .Register  &= 0x0F;
  (*((volatile Register_t *)0xF82)) .Register  |= (v3 & 0xF0);
 toggle();

  (*((volatile Register_t *)0xF82)) .Register  &= 0x0F;
  (*((volatile Register_t *)0xF82)) .Register  |= ((v3 & 0x0F)<<4);
 toggle();
 }

 void lcd_init()
 {
 lcd_cmd_hf(0x30);
 lcd_cmd_hf(0x30);
 lcd_cmd_hf(0x20);
 lcd_cmd(0x28);
 lcd_cmd(0x0C);
 lcd_cmd(0x01);
 lcd_cmd(0x06);
 lcd_cmd(0x80);
 }

 void delay(int ms)
 {
 int i,j;
 for(i=0;i<=ms;i++)
 for(j=0;j<=120;j++);
 }

 void lcd_msg(char *c)
 {
 while(*c != 0)
 lcd_dwr(*c++);
 }

 void lcd_rig_sh()
 {
 lcd_cmd(0x1C);
 delay(100);
 }

 void lcd_lef_sh()
 {

 lcd_cmd(0x18);
 delay_ms(30);
 }
