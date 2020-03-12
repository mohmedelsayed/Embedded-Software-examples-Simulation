
_interrupt_init:

;interrupt.c,4 :: 		void interrupt_init( void ){
;interrupt.c,5 :: 		INTCON_REG.Register_Bits.Bit1 =0 ; // The INT0 external interrupt did not occur
	BCF         4082, 1 
;interrupt.c,6 :: 		TRISB_REG.Register_Bits.Bit0 = 1 ; // Make int0_Bit Input
	BSF         3987, 0 
;interrupt.c,7 :: 		INTCON_REG.Register_Bits.Bit7 =1 ; // important for Enables interrupts
	BSF         4082, 7 
;interrupt.c,8 :: 		INTCON_REG.Register_Bits.Bit6 =1 ; // important for Enables interrupts
	BSF         4082, 6 
;interrupt.c,9 :: 		INTCON_REG.Register_Bits.Bit4 =1 ; // Enables the INT0 external interrupt
	BSF         4082, 4 
;interrupt.c,10 :: 		INTCON_REG.Register_Bits.Bit3 =1 ; // Enables the RB port change interrupt
	BSF         4082, 3 
;interrupt.c,11 :: 		INTCON2_REG.Register_Bits.Bit6 =0 ; // Interrupt on Falling edge
	BCF         4081, 6 
;interrupt.c,12 :: 		RBIF_bit = 0;
	BCF         RBIF_bit+0, BitPos(RBIF_bit+0) 
;interrupt.c,14 :: 		}                                    //
L_end_interrupt_init:
	RETURN      0
; end of _interrupt_init

_interrupt:

;interrupt.c,16 :: 		void interrupt( void )
;interrupt.c,18 :: 		if ( INTCON_REG.Register_Bits.Bit1 ==1 )
	BTFSS       4082, 1 
	GOTO        L_interrupt0
;interrupt.c,20 :: 		INTCON_REG.Register_Bits.Bit1 =0;
	BCF         4082, 1 
;interrupt.c,21 :: 		LED1 = ~ LED1 ;
	BTG         3970, 4 
;interrupt.c,23 :: 		}
L_interrupt0:
;interrupt.c,24 :: 		if(RBIF_bit == 1 && RB4_bit == 1){
	BTFSS       RBIF_bit+0, BitPos(RBIF_bit+0) 
	GOTO        L_interrupt3
	BTFSS       RB4_bit+0, BitPos(RB4_bit+0) 
	GOTO        L_interrupt3
L__interrupt27:
;interrupt.c,25 :: 		RBIF_bit = 0;
	BCF         RBIF_bit+0, BitPos(RBIF_bit+0) 
;interrupt.c,26 :: 		RC4_bit = 1;
	BSF         RC4_bit+0, BitPos(RC4_bit+0) 
;interrupt.c,27 :: 		}
	GOTO        L_interrupt4
L_interrupt3:
;interrupt.c,28 :: 		else if(RBIF_bit == 1 && RB4_bit == 0){
	BTFSS       RBIF_bit+0, BitPos(RBIF_bit+0) 
	GOTO        L_interrupt7
	BTFSC       RB4_bit+0, BitPos(RB4_bit+0) 
	GOTO        L_interrupt7
L__interrupt26:
;interrupt.c,29 :: 		RBIF_bit = 0;
	BCF         RBIF_bit+0, BitPos(RBIF_bit+0) 
;interrupt.c,30 :: 		RC4_bit = 0;
	BCF         RC4_bit+0, BitPos(RC4_bit+0) 
;interrupt.c,31 :: 		}
L_interrupt7:
L_interrupt4:
;interrupt.c,33 :: 		if(RBIF_bit == 1 && RB5_bit == 1){
	BTFSS       RBIF_bit+0, BitPos(RBIF_bit+0) 
	GOTO        L_interrupt10
	BTFSS       RB5_bit+0, BitPos(RB5_bit+0) 
	GOTO        L_interrupt10
L__interrupt25:
;interrupt.c,34 :: 		RBIF_bit = 0;
	BCF         RBIF_bit+0, BitPos(RBIF_bit+0) 
;interrupt.c,35 :: 		RC4_bit = 1;
	BSF         RC4_bit+0, BitPos(RC4_bit+0) 
;interrupt.c,36 :: 		}
	GOTO        L_interrupt11
L_interrupt10:
;interrupt.c,37 :: 		else if(RBIF_bit == 1 && RB5_bit == 0){
	BTFSS       RBIF_bit+0, BitPos(RBIF_bit+0) 
	GOTO        L_interrupt14
	BTFSC       RB5_bit+0, BitPos(RB5_bit+0) 
	GOTO        L_interrupt14
L__interrupt24:
;interrupt.c,38 :: 		RBIF_bit = 0;
	BCF         RBIF_bit+0, BitPos(RBIF_bit+0) 
;interrupt.c,39 :: 		RC4_bit = 0;
	BCF         RC4_bit+0, BitPos(RC4_bit+0) 
;interrupt.c,40 :: 		}
L_interrupt14:
L_interrupt11:
;interrupt.c,42 :: 		if(RBIF_bit == 1 && RB6_bit == 1){
	BTFSS       RBIF_bit+0, BitPos(RBIF_bit+0) 
	GOTO        L_interrupt17
	BTFSS       RB6_bit+0, BitPos(RB6_bit+0) 
	GOTO        L_interrupt17
L__interrupt23:
;interrupt.c,43 :: 		RBIF_bit = 0;
	BCF         RBIF_bit+0, BitPos(RBIF_bit+0) 
;interrupt.c,44 :: 		RC4_bit = 1;
	BSF         RC4_bit+0, BitPos(RC4_bit+0) 
;interrupt.c,45 :: 		}
	GOTO        L_interrupt18
L_interrupt17:
;interrupt.c,46 :: 		else if(RBIF_bit == 1 && RB6_bit == 0){
	BTFSS       RBIF_bit+0, BitPos(RBIF_bit+0) 
	GOTO        L_interrupt21
	BTFSC       RB6_bit+0, BitPos(RB6_bit+0) 
	GOTO        L_interrupt21
L__interrupt22:
;interrupt.c,47 :: 		RBIF_bit = 0;
	BCF         RBIF_bit+0, BitPos(RBIF_bit+0) 
;interrupt.c,48 :: 		RC4_bit = 0;
	BCF         RC4_bit+0, BitPos(RC4_bit+0) 
;interrupt.c,49 :: 		}
L_interrupt21:
L_interrupt18:
;interrupt.c,50 :: 		}
L_end_interrupt:
L__interrupt30:
	RETFIE      1
; end of _interrupt
