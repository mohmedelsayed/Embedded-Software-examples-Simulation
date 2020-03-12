
_main:

;Timer1.c,3 :: 		void main() {
;Timer1.c,4 :: 		TRISC_REG.Register = 0;
	CLRF        3988 
;Timer1.c,5 :: 		RC0_bit = 0;
	BCF         RC0_bit+0, BitPos(RC0_bit+0) 
;Timer1.c,6 :: 		timer1_init();
	CALL        _timer1_init+0, 0
;Timer1.c,7 :: 		timer1_on();
	CALL        _timer1_on+0, 0
;Timer1.c,8 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
