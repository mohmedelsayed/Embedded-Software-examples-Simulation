
_main:

;lcd_d.c,23 :: 		void main()
;lcd_d.c,25 :: 		port_lcd_d = 0x00;  //---P0 as Output
	MOVLW       148
	MOVWF       FSR1 
	MOVLW       15
	MOVWF       FSR1H 
	CLRF        POSTINC1+0 
;lcd_d.c,26 :: 		lcd_init();//---LCD initialize
	CALL        _lcd_init+0, 0
;lcd_d.c,27 :: 		while(1){
L_main0:
;lcd_d.c,28 :: 		lcd_cmd(0x96);
	MOVLW       150
	MOVWF       FARG_lcd_cmd_v2+0 
	CALL        _lcd_cmd+0, 0
;lcd_d.c,29 :: 		lcd_msg(" Sayed Super-Market");
	MOVLW       ?lstr1_lcd_d+0
	MOVWF       FARG_lcd_msg_c+0 
	MOVLW       hi_addr(?lstr1_lcd_d+0)
	MOVWF       FARG_lcd_msg_c+1 
	CALL        _lcd_msg+0, 0
;lcd_d.c,30 :: 		lcd_lef_sh();
	CALL        _lcd_lef_sh+0, 0
;lcd_d.c,47 :: 		}
	GOTO        L_main0
;lcd_d.c,49 :: 		}
L_end_main:
	GOTO        $+0
; end of _main

_toggle:

;lcd_d.c,52 :: 		void toggle()
;lcd_d.c,54 :: 		en = 1;             //-----Latching data in to LCD data register using High to Low signal
	MOVLW       130
	MOVWF       FSR1 
	MOVLW       15
	MOVWF       FSR1H 
	BSF         POSTINC1+0, 1 
;lcd_d.c,55 :: 		delay(1);
	MOVLW       1
	MOVWF       FARG_delay_ms+0 
	MOVLW       0
	MOVWF       FARG_delay_ms+1 
	CALL        _delay+0, 0
;lcd_d.c,56 :: 		en = 0;
	MOVLW       130
	MOVWF       FSR1 
	MOVLW       15
	MOVWF       FSR1H 
	BCF         POSTINC1+0, 1 
;lcd_d.c,57 :: 		}
L_end_toggle:
	RETURN      0
; end of _toggle

_lcd_cmd_hf:

;lcd_d.c,59 :: 		void lcd_cmd_hf(char v1)
;lcd_d.c,61 :: 		rs = 0;                             //----Selecting register as Command register
	MOVLW       130
	MOVWF       FSR1 
	MOVLW       15
	MOVWF       FSR1H 
	BCF         POSTINC1+0, 0 
;lcd_d.c,62 :: 		port_lcd &= 0x0F;                    //----clearing the Higher 4 bits
	MOVLW       130
	MOVWF       R1 
	MOVLW       15
	MOVWF       R2 
	MOVFF       R1, FSR0
	MOVFF       R2, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVLW       15
	ANDWF       R0, 1 
	MOVFF       R1, FSR1
	MOVFF       R2, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;lcd_d.c,63 :: 		port_lcd |= (v1 & 0xF0);     //----Masking higher 4 bits and sending to LCD
	MOVLW       130
	MOVWF       R2 
	MOVLW       15
	MOVWF       R3 
	MOVLW       240
	ANDWF       FARG_lcd_cmd_hf_v1+0, 0 
	MOVWF       R1 
	MOVFF       R2, FSR0
	MOVFF       R3, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R1, 0 
	IORWF       R0, 1 
	MOVFF       R2, FSR1
	MOVFF       R3, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;lcd_d.c,64 :: 		toggle();
	CALL        _toggle+0, 0
;lcd_d.c,65 :: 		}
L_end_lcd_cmd_hf:
	RETURN      0
; end of _lcd_cmd_hf

_lcd_cmd:

;lcd_d.c,67 :: 		void lcd_cmd(char v2)
;lcd_d.c,69 :: 		rs = 0;                             //----Selecting register as command register
	MOVLW       130
	MOVWF       FSR1 
	MOVLW       15
	MOVWF       FSR1H 
	BCF         POSTINC1+0, 0 
;lcd_d.c,70 :: 		port_lcd &= 0x0F;                    //----clearing the Higher 4 bits
	MOVLW       130
	MOVWF       R1 
	MOVLW       15
	MOVWF       R2 
	MOVFF       R1, FSR0
	MOVFF       R2, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVLW       15
	ANDWF       R0, 1 
	MOVFF       R1, FSR1
	MOVFF       R2, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;lcd_d.c,71 :: 		port_lcd |= (v2 & 0xF0);     //----Masking higher 4 bits and sending to LCD
	MOVLW       130
	MOVWF       R2 
	MOVLW       15
	MOVWF       R3 
	MOVLW       240
	ANDWF       FARG_lcd_cmd_v2+0, 0 
	MOVWF       R1 
	MOVFF       R2, FSR0
	MOVFF       R3, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R1, 0 
	IORWF       R0, 1 
	MOVFF       R2, FSR1
	MOVFF       R3, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;lcd_d.c,72 :: 		toggle();
	CALL        _toggle+0, 0
;lcd_d.c,74 :: 		port_lcd &= 0x0F;                        //----clearing the Higher 4 bits
	MOVLW       130
	MOVWF       R1 
	MOVLW       15
	MOVWF       R2 
	MOVFF       R1, FSR0
	MOVFF       R2, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVLW       15
	ANDWF       R0, 1 
	MOVFF       R1, FSR1
	MOVFF       R2, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;lcd_d.c,75 :: 		port_lcd |= ((v2 & 0x0F)<<4);  //----Masking lower 4 bits and sending to LCD
	MOVLW       130
	MOVWF       R3 
	MOVLW       15
	MOVWF       R4 
	MOVLW       15
	ANDWF       FARG_lcd_cmd_v2+0, 0 
	MOVWF       R2 
	MOVF        R2, 0 
	MOVWF       R1 
	RLCF        R1, 1 
	BCF         R1, 0 
	RLCF        R1, 1 
	BCF         R1, 0 
	RLCF        R1, 1 
	BCF         R1, 0 
	RLCF        R1, 1 
	BCF         R1, 0 
	MOVFF       R3, FSR0
	MOVFF       R4, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R1, 0 
	IORWF       R0, 1 
	MOVFF       R3, FSR1
	MOVFF       R4, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;lcd_d.c,76 :: 		toggle();
	CALL        _toggle+0, 0
;lcd_d.c,77 :: 		}
L_end_lcd_cmd:
	RETURN      0
; end of _lcd_cmd

_lcd_dwr:

;lcd_d.c,79 :: 		void lcd_dwr(char v3)
;lcd_d.c,81 :: 		rs = 1;                                 //----Selecting register as command register
	MOVLW       130
	MOVWF       FSR1 
	MOVLW       15
	MOVWF       FSR1H 
	BSF         POSTINC1+0, 0 
;lcd_d.c,82 :: 		port_lcd &= 0x0F;                        //----clearing the Higher 4 bits
	MOVLW       130
	MOVWF       R1 
	MOVLW       15
	MOVWF       R2 
	MOVFF       R1, FSR0
	MOVFF       R2, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVLW       15
	ANDWF       R0, 1 
	MOVFF       R1, FSR1
	MOVFF       R2, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;lcd_d.c,83 :: 		port_lcd |= (v3 & 0xF0);     //----Masking higher 4 bits and sending to LCD
	MOVLW       130
	MOVWF       R2 
	MOVLW       15
	MOVWF       R3 
	MOVLW       240
	ANDWF       FARG_lcd_dwr_v3+0, 0 
	MOVWF       R1 
	MOVFF       R2, FSR0
	MOVFF       R3, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R1, 0 
	IORWF       R0, 1 
	MOVFF       R2, FSR1
	MOVFF       R3, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;lcd_d.c,84 :: 		toggle();
	CALL        _toggle+0, 0
;lcd_d.c,86 :: 		port_lcd &= 0x0F;                        //----clearing the Higher 4 bits
	MOVLW       130
	MOVWF       R1 
	MOVLW       15
	MOVWF       R2 
	MOVFF       R1, FSR0
	MOVFF       R2, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVLW       15
	ANDWF       R0, 1 
	MOVFF       R1, FSR1
	MOVFF       R2, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;lcd_d.c,87 :: 		port_lcd |= ((v3 & 0x0F)<<4);  //----Masking lower 4 bits and sending to LCD
	MOVLW       130
	MOVWF       R3 
	MOVLW       15
	MOVWF       R4 
	MOVLW       15
	ANDWF       FARG_lcd_dwr_v3+0, 0 
	MOVWF       R2 
	MOVF        R2, 0 
	MOVWF       R1 
	RLCF        R1, 1 
	BCF         R1, 0 
	RLCF        R1, 1 
	BCF         R1, 0 
	RLCF        R1, 1 
	BCF         R1, 0 
	RLCF        R1, 1 
	BCF         R1, 0 
	MOVFF       R3, FSR0
	MOVFF       R4, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R1, 0 
	IORWF       R0, 1 
	MOVFF       R3, FSR1
	MOVFF       R4, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;lcd_d.c,88 :: 		toggle();
	CALL        _toggle+0, 0
;lcd_d.c,89 :: 		}
L_end_lcd_dwr:
	RETURN      0
; end of _lcd_dwr

_lcd_init:

;lcd_d.c,91 :: 		void lcd_init()
;lcd_d.c,93 :: 		lcd_cmd_hf(0x30);       //-----Sequence for initializing LCD
	MOVLW       48
	MOVWF       FARG_lcd_cmd_hf_v1+0 
	CALL        _lcd_cmd_hf+0, 0
;lcd_d.c,94 :: 		lcd_cmd_hf(0x30);       //-----     "            "              "               "
	MOVLW       48
	MOVWF       FARG_lcd_cmd_hf_v1+0 
	CALL        _lcd_cmd_hf+0, 0
;lcd_d.c,95 :: 		lcd_cmd_hf(0x20);       //-----     "            "              "               "
	MOVLW       32
	MOVWF       FARG_lcd_cmd_hf_v1+0 
	CALL        _lcd_cmd_hf+0, 0
;lcd_d.c,96 :: 		lcd_cmd(0x28);          //-----Selecting 16 x 2 LCD in 4Bit mode
	MOVLW       40
	MOVWF       FARG_lcd_cmd_v2+0 
	CALL        _lcd_cmd+0, 0
;lcd_d.c,97 :: 		lcd_cmd(0x0C);          //-----Display ON Cursor OFF
	MOVLW       12
	MOVWF       FARG_lcd_cmd_v2+0 
	CALL        _lcd_cmd+0, 0
;lcd_d.c,98 :: 		lcd_cmd(0x01);          //-----Clear display
	MOVLW       1
	MOVWF       FARG_lcd_cmd_v2+0 
	CALL        _lcd_cmd+0, 0
;lcd_d.c,99 :: 		lcd_cmd(0x06);          //-----Cursor Auto Increment
	MOVLW       6
	MOVWF       FARG_lcd_cmd_v2+0 
	CALL        _lcd_cmd+0, 0
;lcd_d.c,100 :: 		lcd_cmd(0x80);          //-----1st line 1st location of LCD
	MOVLW       128
	MOVWF       FARG_lcd_cmd_v2+0 
	CALL        _lcd_cmd+0, 0
;lcd_d.c,101 :: 		}
L_end_lcd_init:
	RETURN      0
; end of _lcd_init

_delay:

;lcd_d.c,103 :: 		void delay(int ms)
;lcd_d.c,106 :: 		for(i=0;i<=ms;i++)
	CLRF        R1 
	CLRF        R2 
L_delay2:
	MOVLW       128
	XORWF       FARG_delay_ms+1, 0 
	MOVWF       R0 
	MOVLW       128
	XORWF       R2, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__delay18
	MOVF        R1, 0 
	SUBWF       FARG_delay_ms+0, 0 
L__delay18:
	BTFSS       STATUS+0, 0 
	GOTO        L_delay3
;lcd_d.c,107 :: 		for(j=0;j<=120;j++);
	CLRF        R3 
	CLRF        R4 
L_delay5:
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       R4, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__delay19
	MOVF        R3, 0 
	SUBLW       120
L__delay19:
	BTFSS       STATUS+0, 0 
	GOTO        L_delay6
	INFSNZ      R3, 1 
	INCF        R4, 1 
	GOTO        L_delay5
L_delay6:
;lcd_d.c,106 :: 		for(i=0;i<=ms;i++)
	INFSNZ      R1, 1 
	INCF        R2, 1 
;lcd_d.c,107 :: 		for(j=0;j<=120;j++);
	GOTO        L_delay2
L_delay3:
;lcd_d.c,108 :: 		}
L_end_delay:
	RETURN      0
; end of _delay

_lcd_msg:

;lcd_d.c,110 :: 		void lcd_msg(char *c)
;lcd_d.c,112 :: 		while(*c != 0)      //----Wait till all String are passed to LCD
L_lcd_msg8:
	MOVFF       FARG_lcd_msg_c+0, FSR0
	MOVFF       FARG_lcd_msg_c+1, FSR0H
	MOVF        POSTINC0+0, 0 
	XORLW       0
	BTFSC       STATUS+0, 2 
	GOTO        L_lcd_msg9
;lcd_d.c,113 :: 		lcd_dwr(*c++);  //----Send the String to LCD
	MOVFF       FARG_lcd_msg_c+0, FSR0
	MOVFF       FARG_lcd_msg_c+1, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_lcd_dwr_v3+0 
	CALL        _lcd_dwr+0, 0
	INFSNZ      FARG_lcd_msg_c+0, 1 
	INCF        FARG_lcd_msg_c+1, 1 
	GOTO        L_lcd_msg8
L_lcd_msg9:
;lcd_d.c,114 :: 		}
L_end_lcd_msg:
	RETURN      0
; end of _lcd_msg

_lcd_rig_sh:

;lcd_d.c,116 :: 		void lcd_rig_sh()
;lcd_d.c,118 :: 		lcd_cmd(0x1C);      //----Command for right Shift
	MOVLW       28
	MOVWF       FARG_lcd_cmd_v2+0 
	CALL        _lcd_cmd+0, 0
;lcd_d.c,119 :: 		delay(100);
	MOVLW       100
	MOVWF       FARG_delay_ms+0 
	MOVLW       0
	MOVWF       FARG_delay_ms+1 
	CALL        _delay+0, 0
;lcd_d.c,120 :: 		}
L_end_lcd_rig_sh:
	RETURN      0
; end of _lcd_rig_sh

_lcd_lef_sh:

;lcd_d.c,122 :: 		void lcd_lef_sh()
;lcd_d.c,125 :: 		lcd_cmd(0x18);      //----Command for Left Shift
	MOVLW       24
	MOVWF       FARG_lcd_cmd_v2+0 
	CALL        _lcd_cmd+0, 0
;lcd_d.c,126 :: 		delay_ms(30);
	MOVLW       39
	MOVWF       R12, 0
	MOVLW       245
	MOVWF       R13, 0
L_lcd_lef_sh10:
	DECFSZ      R13, 1, 1
	BRA         L_lcd_lef_sh10
	DECFSZ      R12, 1, 1
	BRA         L_lcd_lef_sh10
;lcd_d.c,127 :: 		}
L_end_lcd_lef_sh:
	RETURN      0
; end of _lcd_lef_sh
