
_main:

;MyProject.c,4 :: 		void main() {
;MyProject.c,7 :: 		TRISC_REG.Register = 0;
	CLRF        3988 
;MyProject.c,8 :: 		interrupt_init();
	CALL        _interrupt_init+0, 0
;MyProject.c,9 :: 		LED1 = 0;
	BCF         3970, 4 
;MyProject.c,10 :: 		while( 1 )
L_main0:
;MyProject.c,12 :: 		LED0  = 0;
	BCF         3970, 0 
;MyProject.c,13 :: 		Delay_ms(100);
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       221
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 1
	BRA         L_main2
	DECFSZ      R12, 1, 1
	BRA         L_main2
	NOP
	NOP
;MyProject.c,14 :: 		LED0 = 1;
	BSF         3970, 0 
;MyProject.c,15 :: 		Delay_ms(100);
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       221
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	NOP
	NOP
;MyProject.c,16 :: 		}
	GOTO        L_main0
;MyProject.c,20 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
