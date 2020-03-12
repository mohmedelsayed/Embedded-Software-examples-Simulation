
_main:

;Timer1.c,3 :: 		void main() {
;Timer1.c,4 :: 		TRISC_REG.Register = 0;
	CLRF        3988 
;Timer1.c,5 :: 		RC0_bit = 0;
	BCF         RC0_bit+0, BitPos(RC0_bit+0) 
;Timer1.c,6 :: 		timer0_init();
	CALL        _timer0_init+0, 0
;Timer1.c,7 :: 		timer0_on();
	CALL        _timer0_on+0, 0
;Timer1.c,8 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
