
_timer1_init:

;timer.c,3 :: 		void timer1_init(void)
;timer.c,5 :: 		TMR1IF_bit = 0;
	BCF         TMR1IF_bit+0, BitPos(TMR1IF_bit+0) 
;timer.c,6 :: 		TMR1H         = 0x0B;
	MOVLW       11
	MOVWF       TMR1H+0 
;timer.c,7 :: 		TMR1L         = 0xDC;
	MOVLW       220
	MOVWF       TMR1L+0 
;timer.c,9 :: 		INTCON_REG.Register_Bits.Bit6 = 1;   //PEIE
	BSF         4082, 6 
;timer.c,10 :: 		INTCON_REG.Register_Bits.Bit7 = 1;   //GIEH
	BSF         4082, 7 
;timer.c,11 :: 		PIE1_REG.Register_Bits.Bit0   = 1;    //TMR1IE
	BSF         3997, 0 
;timer.c,12 :: 		T1CON_REG.Register_Bits.Bit0  = 0;   //TMR1ON
	BCF         4045, 0 
;timer.c,13 :: 		T1CON_REG.Register_Bits.Bit1  = 0;   //TMR1CS
	BCF         4045, 1 
;timer.c,14 :: 		T1CON_REG.Register_Bits.Bit4  = 1;   //T1CKPS0
	BSF         4045, 4 
;timer.c,15 :: 		T1CON_REG.Register_Bits.Bit5  = 1;   //T1CKPS1
	BSF         4045, 5 
;timer.c,18 :: 		}
L_end_timer1_init:
	RETURN      0
; end of _timer1_init

_interrupt:

;timer.c,19 :: 		void interrupt (void)
;timer.c,21 :: 		if ( TMR1IF_bit)
	BTFSS       TMR1IF_bit+0, BitPos(TMR1IF_bit+0) 
	GOTO        L_interrupt0
;timer.c,25 :: 		TMR1H         = 0x0B;
	MOVLW       11
	MOVWF       TMR1H+0 
;timer.c,26 :: 		TMR1L         = 0xDC;
	MOVLW       220
	MOVWF       TMR1L+0 
;timer.c,27 :: 		overFlowsCounter++ ;
	INCF        _overFlowsCounter+0, 1 
;timer.c,28 :: 		if ( overFlowsCounter == 2)
	MOVF        _overFlowsCounter+0, 0 
	XORLW       2
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt1
;timer.c,31 :: 		RC0_bit = ~ RC0_Bit;
	BTG         RC0_bit+0, BitPos(RC0_bit+0) 
;timer.c,32 :: 		overFlowsCounter=0;
	CLRF        _overFlowsCounter+0 
;timer.c,33 :: 		}
L_interrupt1:
;timer.c,35 :: 		TMR1IF_bit =   0 ;
	BCF         TMR1IF_bit+0, BitPos(TMR1IF_bit+0) 
;timer.c,39 :: 		}
L_interrupt0:
;timer.c,41 :: 		}
L_end_interrupt:
L__interrupt4:
	RETFIE      1
; end of _interrupt

_timer1_on:

;timer.c,43 :: 		void timer1_on (void)
;timer.c,45 :: 		T1CON_REG.Register_Bits.Bit0 = 1;   //TMR1ON
	BSF         4045, 0 
;timer.c,47 :: 		}
L_end_timer1_on:
	RETURN      0
; end of _timer1_on

_timer1_off:

;timer.c,48 :: 		void timer1_off(void)
;timer.c,50 :: 		T1CON_REG.Register_Bits.Bit0 = 0;   //TMR1ON
	BCF         4045, 0 
;timer.c,51 :: 		}
L_end_timer1_off:
	RETURN      0
; end of _timer1_off
