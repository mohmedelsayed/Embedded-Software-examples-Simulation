
_main:

;Seven_Seg1.c,6 :: 		void main() {
;Seven_Seg1.c,7 :: 		TRISD_REG.Register_Bits.Bit1=0;
	MOVLW       149
	MOVWF       FSR1 
	MOVLW       15
	MOVWF       FSR1H 
	BCF         POSTINC1+0, 1 
;Seven_Seg1.c,8 :: 		PORTD_REG.Register_Bits.Bit1=0;
	MOVLW       131
	MOVWF       FSR1 
	MOVLW       15
	MOVWF       FSR1H 
	BCF         POSTINC1+0, 1 
;Seven_Seg1.c,9 :: 		seven_segment_print_port_nuumber_init(PORTC_R);
	MOVLW       2
	MOVWF       FARG_seven_segment_print_port_nuumber_init_port+0 
	CALL        _seven_segment_print_port_nuumber_init+0, 0
;Seven_Seg1.c,10 :: 		while(1){
L_main0:
;Seven_Seg1.c,11 :: 		if (PORTD_REG.Register_Bits.Bit1==1){
	MOVLW       131
	MOVWF       FSR0 
	MOVLW       15
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	BTFSS       R0, 1 
	GOTO        L_main2
;Seven_Seg1.c,12 :: 		for(counter=0; counter<100; counter++){
	CLRF        _counter+0 
L_main3:
	MOVLW       100
	SUBWF       _counter+0, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_main4
;Seven_Seg1.c,13 :: 		seven_segment_print_port_nuumber(PORTC_R, convert_number_seven_segement(counter));
	MOVF        _counter+0, 0 
	MOVWF       FARG_convert_number_seven_segement_number+0 
	CALL        _convert_number_seven_segement+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_seven_segment_print_port_nuumber_number+0 
	MOVLW       2
	MOVWF       FARG_seven_segment_print_port_nuumber_port+0 
	CALL        _seven_segment_print_port_nuumber+0, 0
;Seven_Seg1.c,14 :: 		Delay_ms(250);
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       69
	MOVWF       R12, 0
	MOVLW       169
	MOVWF       R13, 0
L_main6:
	DECFSZ      R13, 1, 1
	BRA         L_main6
	DECFSZ      R12, 1, 1
	BRA         L_main6
	DECFSZ      R11, 1, 1
	BRA         L_main6
	NOP
	NOP
;Seven_Seg1.c,12 :: 		for(counter=0; counter<100; counter++){
	INCF        _counter+0, 1 
;Seven_Seg1.c,15 :: 		}
	GOTO        L_main3
L_main4:
;Seven_Seg1.c,16 :: 		}
L_main2:
;Seven_Seg1.c,17 :: 		}
	GOTO        L_main0
;Seven_Seg1.c,18 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
