
_timer0_init:

;timer.c,3 :: 		void timer0_init(void)
;timer.c,5 :: 		INTCON_REG.Register_Bits.Bit2 = 0;    //TMR0 Overflow Interrupt Flag bit
	BCF         4082, 2 
;timer.c,6 :: 		TMR0L	 = 0xDC;
	MOVLW       220
	MOVWF       TMR0L+0 
;timer.c,7 :: 		TMR0H	 = 0x0B;
	MOVLW       11
	MOVWF       TMR0H+0 
;timer.c,8 :: 		INTCON_REG.Register_Bits.Bit6 = 1;   //PEIE
	BSF         4082, 6 
;timer.c,9 :: 		INTCON_REG.Register_Bits.Bit7 = 1;   //GIEH
	BSF         4082, 7 
;timer.c,10 :: 		INTCON_REG.Register_Bits.Bit5 = 1;   //TMR0 Overflow Interrupt Enable bit
	BSF         4082, 5 
;timer.c,11 :: 		T0CON_REG.Register_Bits.Bit7  = 0;    //Timer0 On/Off Control bit
	BCF         4053, 7 
;timer.c,12 :: 		T0CON_REG.Register_Bits.Bit6  = 0;    //Timer0 8-Bit/16-Bit Control bit
	BCF         4053, 6 
;timer.c,13 :: 		T0CON_REG.Register_Bits.Bit5  = 0;    //Timer0 Clock Source Select bit
	BCF         4053, 5 
;timer.c,14 :: 		T0CON_REG.Register_Bits.Bit4  = 0;    //Timer0 Source Edge Select bit
	BCF         4053, 4 
;timer.c,15 :: 		T0CON_REG.Register_Bits.Bit3  = 0;    //Timer0 Prescaler Assignment bit
	BCF         4053, 3 
;timer.c,16 :: 		T0CON_REG.Register_Bits.Bit2  = 0;    //Timer0 Prescaler Select bits
	BCF         4053, 2 
;timer.c,17 :: 		T0CON_REG.Register_Bits.Bit1  = 1;    //Timer0 Prescaler Select bits
	BSF         4053, 1 
;timer.c,18 :: 		T0CON_REG.Register_Bits.Bit0  = 1;    //Timer0 Prescaler Select bits
	BSF         4053, 0 
;timer.c,25 :: 		}
L_end_timer0_init:
	RETURN      0
; end of _timer0_init

_interrupt:

;timer.c,26 :: 		void interrupt (void)
;timer.c,28 :: 		if ( INTCON_REG.Register_Bits.Bit2)
	BTFSS       4082, 2 
	GOTO        L_interrupt0
;timer.c,30 :: 		{  RC0_bit = ~ RC0_Bit;
	BTG         RC0_bit+0, BitPos(RC0_bit+0) 
;timer.c,31 :: 		TMR0L	 = 0xDC;
	MOVLW       220
	MOVWF       TMR0L+0 
;timer.c,32 :: 		TMR0H	 = 0x0B;
	MOVLW       11
	MOVWF       TMR0H+0 
;timer.c,34 :: 		INTCON_REG.Register_Bits.Bit2 =   0 ;
	BCF         4082, 2 
;timer.c,35 :: 		}
L_interrupt0:
;timer.c,37 :: 		}
L_end_interrupt:
L__interrupt3:
	RETFIE      1
; end of _interrupt

_timer0_on:

;timer.c,39 :: 		void timer0_on (void)
;timer.c,41 :: 		T0CON_REG.Register_Bits.Bit7 = 1;   //TMR1ON
	BSF         4053, 7 
;timer.c,43 :: 		}
L_end_timer0_on:
	RETURN      0
; end of _timer0_on

_timer0_off:

;timer.c,44 :: 		void timer0_off(void)
;timer.c,46 :: 		T0CON_REG.Register_Bits.Bit7 = 0;   //TMR1ON
	BCF         4053, 7 
;timer.c,47 :: 		}
L_end_timer0_off:
	RETURN      0
; end of _timer0_off
