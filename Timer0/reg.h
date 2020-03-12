#ifndef _REG_H
#define _REG_H

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

#define PIN0 (0)
#define PIN1 (1)
#define PIN2 (2)
#define PIN3 (3)
#define PIN4 (4)
#define PIN5 (5)
#define PIN6 (6)
#define PIN7 (7)

#define ACCESS_TYPE (1)
#ifndef ACCESS_TYPE
        #define ACCESS_TYPE (0)
#endif

#if ACCESS_TYPE==0
    #define TRISA_REG (*((volatile uint8_t *)0xF92))
    #define TRISB_REG (*((volatile uint8_t *)0xF93))
    #define TRISC_REG (*((volatile uint8_t *)0xF94))
    #define TRISD_REG (*((volatile uint8_t *)0xF95))
    #define TRISE_REG (*((volatile uint8_t *)0xF96))
    #define PORTA_REG (*((volatile uint8_t *)0xF80))
    #define PORTB_REG (*((volatile uint8_t *)0xF81))
    #define PORTC_REG (*((volatile uint8_t *)0xF82))
    #define PORTD_REG (*((volatile uint8_t *)0xF83))
    #define PORTE_REG (*((volatile uint8_t *)0xF84))
/*---------------------TOS_REG------------------------*/
    #define TOSU_REG (*((volatile uint8_t *)0xFFF))
    #define TOSH_REG (*((volatile uint8_t *)0xFFE))
    #define TOSL_REG (*((volatile uint8_t *)0xFFD))
/*---------------------STKPTR_REG------------------------*/
    #define STKPTR_REG (*((volatile uint8_t *)0xFFC))
/*---------------------PCLAT_REG------------------------*/
    #define PCLATU_REG (*((volatile uint8_t *)0xFFB))
    #define PCLATH_REG (*((volatile uint8_t *)0xFFA))
    /*---------------------PCL_REG------------------------*/
    #define PCL_REG (*((volatile uint8_t *)0xFF9))
/*---------------------TBLPTR_REG------------------------*/
    #define TBLPTRU_REG (*((volatile uint8_t *)0xFF8))
    #define TBLPTRH_REG (*((volatile uint8_t *)0xFF7))
    #define TBLPTRL_REG (*((volatile uint8_t *)0xFF6))
    /*---------------------TABLAT_REG------------------------*/
    #define TABLAT_REG (*((volatile uint8_t *)0xFF5))
/*---------------------PRODH_REG------------------------*/
    #define PRODH_REG (*((volatile uint8_t *)0xFF4))
    #define PRODL_REG (*((volatile uint8_t *)0xFF3))
/*---------------------INTCON_REG------------------------*/
    #define INTCON_REG (*((volatile uint8_t *)0xFF2))
    #define INTCON2_REG (*((volatile uint8_t *)0xFF1))
    #define INTCON3_REG (*((volatile uint8_t *)0xFF0))
/*---------------------INDF_REG------------------------*/
    #define INDF0_REG (*((volatile uint8_t *)0xFEF))
    #define INDF1_REG (*((volatile uint8_t *)0xFE7))
    #define INDF2_REG (*((volatile uint8_t *)0xFDF))
/*---------------------POSTINC_REG------------------------*/
    #define POSTINC0_REG (*((volatile uint8_t *)0xFEE))
    #define POSTINC1_REG (*((volatile uint8_t *)0xFE6))
    #define POSTINC2_REG (*((volatile uint8_t *)0xFDE))
/*---------------------POSTDEC_REG------------------------*/
    #define POSTDEC0_REG (*((volatile uint8_t *)0xFED))
    #define POSTDEC1_REG (*((volatile uint8_t *)0xFE5))
    #define POSTDEC2_REG (*((volatile uint8_t *)0xFDD))
/*---------------------PREINC_REG------------------------*/
    #define PREINC0_REG (*((volatile uint8_t *)0xFEC))
    #define PREINC1_REG (*((volatile uint8_t *)0xFE4))
    #define PREINC2_REG (*((volatile uint8_t *)0xFDC))
/*---------------------PLUSW0_REG------------------------*/
    #define PLUSW0_REG (*((volatile uint8_t *)0xFEB))
    #define PLUSW1_REG (*((volatile uint8_t *)0xFE3))
    #define PLUSW2_REG (*((volatile uint8_t *)0xFDB))
/*---------------------FSR1_REG------------------------*/
    #define FSR1H_REG (*((volatile uint8_t *)0xFE2))
    #define FSR1L_REG (*((volatile uint8_t *)0xFE1))
/*---------------------FSR2_REG------------------------*/
    #define FSR2H_REG (*((volatile uint8_t *)0xFDA))
    #define FSR2L_REG (*((volatile uint8_t *)0xFD9))
/*---------------------BSR_REG------------------------*/
    #define BSR_REG (*((volatile uint8_t *)0xFE0))
/*---------------------STATUS_REG------------------------*/
    #define STATUS_REG (*((volatile uint8_t *)0xFD8))
/*---------------------TMR_REG------------------------*/
    #define TMR0H_REG (*((volatile uint8_t *)0xFD7))
    #define TMR0L_REG (*((volatile uint8_t *)0xFD6))
    #define TMR1H_REG (*((volatile uint8_t *)0xFCF))
    #define TMR1L_REG (*((volatile uint8_t *)0xFCE))
    #define TMR2_REG (*((volatile uint8_t *)0xFCC))
    #define TMR3H_REG (*((volatile uint8_t *)0xFB3))
    #define TMR3L_REG (*((volatile uint8_t *)0xFB2))
/*---------------------TCON_REG------------------------*/
    #define T0CON_REG (*((volatile uint8_t *)0xFD5))
    #define T1CON_REG (*((volatile uint8_t *)0xFCD))
    #define T2CON_REG (*((volatile uint8_t *)0xFCA))
    #define T3CON_REG (*((volatile uint8_t *)0xFB1))
/*---------------------OSCCON_REG------------------------*/
    #define OSCCON_REG (*((volatile uint8_t *)0xFD3))
/*---------------------HLVDCON_REG------------------------*/
    #define HLVDCON_REG (*((volatile uint8_t *)0xFD2))
/*---------------------WDTCON_REG------------------------*/
    #define WDTCON_REG (*((volatile uint8_t *)0xFD1))
/*---------------------RCON_REG------------------------*/
    #define RCON_REG (*((volatile uint8_t *)0xFD0))
/*---------------------PR2_REG------------------------*/
    #define PR2_REG (*((volatile uint8_t *)0xFCB))
/*---------------------T2CON_REG------------------------*/
    #define T2CON_REG (*((volatile uint8_t *)0xFCA))
/*---------------------SSPBUF_REG------------------------*/
    #define SSPBUF_REG (*((volatile uint8_t *)0xFC9))
/*---------------------SSPADD_REG------------------------*/
    #define SSPADD_REG (*((volatile uint8_t *)0xFC8))
/*---------------------SSPSTAT_REG------------------------*/
   #define SSPSTAT_REG (*((volatile uint8_t *)0xFC7))
/*---------------------SSPCON_REG------------------------*/
    #define SSPCON1_REG (*((volatile uint8_t *)0xFC6))
    #define SSPCON2_REG (*((volatile uint8_t *)0xFC5))
/*---------------------ADRES_REG------------------------*/
    #define ADRESH_REG (*((volatile uint8_t *)0xFC4))
    #define ADRESL_REG (*((volatile uint8_t *)0xFC3))
/*---------------------ADCON_REG------------------------*/
    #define ADCON0_REG (*((volatile uint8_t *)0xFC2))
    #define ADCON1_REG (*((volatile uint8_t *)0xFC1))
    #define ADCON2_REG (*((volatile uint8_t *)0xFC0))
/*---------------------CCPR_REG------------------------*/
    #define CCPR1H_REG (*((volatile uint8_t *)0xFBF))
    #define CCPR1L_REG (*((volatile uint8_t *)0xFBE))
    #define CCPR2H_REG (*((volatile uint8_t *)0xFBC))
    #define CCPR2L_REG (*((volatile uint8_t *)0xFBB))
/*---------------------CCPCON_REG------------------------*/
    #define CCP1CON_REG (*((volatile uint8_t *)0xFBD))
    #define CCP2CON_REG (*((volatile uint8_t *)0xFBA))
/*---------------------BAUDCON_REG------------------------*/
    #define BAUDCON_REG (*((volatile uint8_t *)0xFB8))
/*---------------------PWM1CON_REG------------------------*/
    #define PWM1CON_REG (*((volatile uint8_t *)0xFB7))
/*---------------------ECCP1AS_REG------------------------*/
    #define ECCP1AS_REG (*((volatile uint8_t *)0xFB6))
/*---------------------CVRCON_REG------------------------*/
    #define CVRCON_REG (*((volatile uint8_t *)0xFB5))
/*---------------------CMCON_REG------------------------*/
    #define CMCON_REG (*((volatile uint8_t *)0xFB4))
/*---------------------SPBRG_REG------------------------*/
    #define SPBRG_REG (*((volatile uint8_t *)0xFAF))
    #define SPBRGH_REG (*((volatile uint8_t *)0xFB0))

/*---------------------RCREG_REG------------------------*/
    #define RCREG_REG (*((volatile uint8_t *)0xFAE))
    #define RCSTA_REG (*((volatile uint8_t *)0xFAB))
/*---------------------TX_REG------------------------*/
    #define TXREG_REG (*((volatile uint8_t *)0xFAD))
    #define TXSTA_REG (*((volatile uint8_t *)0xFAC))

/*---------------------EEADR_REG------------------------*/
    #define EEADR_REG (*((volatile uint8_t *)0xFA9))
    #define EEADRH_REG (*((volatile uint8_t *)0xFAA))
/*---------------------EEDATA_REG------------------------*/
    #define EEDATA_REG (*((volatile uint8_t *)0xFA8))
/*---------------------EECON_REG------------------------*/
    #define EECON1_REG (*((volatile uint8_t *)0xFA6))
    #define EECON2_REG (*((volatile uint8_t *)0xF82))
/*---------------------IPR_REG------------------------*/
    #define IPR1_REG (*((volatile uint8_t *)0xF9F))
    #define IPR2_REG (*((volatile uint8_t *)0xFA2))
/*---------------------PIR_REG------------------------*/
    #define PIR1_REG (*((volatile uint8_t *)0xF9E))
    #define PIR2_REG (*((volatile uint8_t *)0xFA1))
/*---------------------PIE_REG------------------------*/
    #define PIE1_REG (*((volatile uint8_t *)0xF9D))
    #define PIE2_REG (*((volatile uint8_t *)0xFA0))
/*---------------------OSCTUNE_REG------------------------*/
    #define OSCTUNE_REG (*((volatile uint8_t *)0xF9B))
/*---------------------LAT_REG------------------------*/
    #define LATA_REG (*((volatile uint8_t *)0xF89))
    #define LATB_REG (*((volatile uint8_t *)0xF8A))
    #define LATC_REG (*((volatile uint8_t *)0xF8B))
    #define LATD_REG (*((volatile uint8_t *)0xF8C))
    #define LATE_REG (*((volatile uint8_t *)0xF8D))

/*---------------------END  REG IF ACCESS TYPE = 0 ------------------------*/

#elif ACCESS_TYPE==1

/*---------------------TRIS_STRUCT------------------------*/

    #define TRISA_REG (*((volatile Register_t *)0xF92))
    #define TRISB_REG (*((volatile Register_t *)0xF93))
    #define TRISC_REG (*((volatile Register_t *)0xF94))
    #define TRISD_REG (*((volatile Register_t *)0xF95))
    #define TRISE_REG (*((volatile Register_t *)0xF96))
    #define PORTA_REG (*((volatile Register_t *)0xF80))
    #define PORTB_REG (*((volatile Register_t *)0xF81))
    #define PORTC_REG (*((volatile Register_t *)0xF82))
    #define PORTD_REG (*((volatile Register_t *)0xF83))
    #define PORTE_REG (*((volatile Register_t *)0xF84))

/*---------------------TOS_REG------------------------*/

    #define TOSU_REG (*((volatile Register_t *)0xFFF))
    #define TOSH_REG (*((volatile Register_t *)0xFFE))
    #define TOSL_REG (*((volatile Register_t *)0xFFD))
/*---------------------STKPTR_REG------------------------*/
    #define STKPTR_REG (*((volatile Register_t *)0xFFC))
/*---------------------PCLAT_REG------------------------*/
    #define PCLATU_REG (*((volatile Register_t *)0xFFB))
    #define PCLATH_REG (*((volatile Register_t *)0xFFA))
    /*---------------------PCL_REG------------------------*/
    #define PCL_REG (*((volatile Register_t *)0xFF9))
/*---------------------TBLPTR_REG------------------------*/
    #define TBLPTRU_REG (*((volatile Register_t *)0xFF8))
    #define TBLPTRH_REG (*((volatile Register_t *)0xFF7))
    #define TBLPTRL_REG (*((volatile Register_t *)0xFF6))
    /*---------------------TABLAT_REG------------------------*/
    #define TABLAT_REG (*((volatile Register_t *)0xFF5))
/*---------------------PRODH_REG------------------------*/
    #define PRODH_REG (*((volatile Register_t *)0xFF4))
    #define PRODL_REG (*((volatile Register_t *)0xFF3))
/*---------------------INTCON_REG------------------------*/
    #define INTCON_REG (*((volatile Register_t *)0xFF2))
    #define INTCON2_REG (*((volatile Register_t *)0xFF1))
    #define INTCON3_REG (*((volatile Register_t *)0xFF0))
/*---------------------INDF_REG------------------------*/
    #define INDF0_REG (*((volatile Register_t *)0xFEF))
    #define INDF1_REG (*((volatile Register_t *)0xFE7))
    #define INDF2_REG (*((volatile Register_t *)0xFDF))
/*---------------------POSTINC_REG------------------------*/
    #define POSTINC0_REG (*((volatile Register_t *)0xFEE))
    #define POSTINC1_REG (*((volatile Register_t *)0xFE6))
    #define POSTINC2_REG (*((volatile Register_t *)0xFDE))
/*---------------------POSTDEC_REG------------------------*/
    #define POSTDEC0_REG (*((volatile Register_t *)0xFED))
    #define POSTDEC1_REG (*((volatile Register_t *)0xFE5))
    #define POSTDEC2_REG (*((volatile Register_t *)0xFDD))
/*---------------------PREINC_REG------------------------*/
    #define PREINC0_REG (*((volatile Register_t *)0xFEC))
    #define PREINC1_REG (*((volatile Register_t *)0xFE4))
    #define PREINC2_REG (*((volatile Register_t *)0xFDC))
/*---------------------PLUSW0_REG------------------------*/
    #define PLUSW0_REG (*((volatile Register_t *)0xFEB))
    #define PLUSW1_REG (*((volatile Register_t *)0xFE3))
    #define PLUSW2_REG (*((volatile Register_t *)0xFDB))
/*---------------------FSR1_REG------------------------*/
    #define FSR1H_REG (*((volatile Register_t *)0xFE2))
    #define FSR1L_REG (*((volatile Register_t *)0xFE1))
/*---------------------FSR2_REG------------------------*/
    #define FSR2H_REG (*((volatile Register_t *)0xFDA))
    #define FSR2L_REG (*((volatile Register_t *)0xFD9))
/*---------------------BSR_REG------------------------*/
    #define BSR_REG (*((volatile Register_t *)0xFE0))
/*---------------------STATUS_REG------------------------*/
    #define STATUS_REG (*((volatile Register_t *)0xFD8))
/*---------------------TMR_REG------------------------*/
    #define TMR0H_REG (*((volatile Register_t *)0xFD7))
    #define TMR0L_REG (*((volatile Register_t *)0xFD6))
    #define TMR1H_REG (*((volatile Register_t *)0xFCF))
    #define TMR1L_REG (*((volatile Register_t *)0xFCE))
    #define TMR2_REG (*((volatile Register_t *)0xFCC))
    #define TMR3H_REG (*((volatile Register_t *)0xFB3))
    #define TMR3L_REG (*((volatile Register_t *)0xFB2))
/*---------------------TCON_REG------------------------*/
    #define T0CON_REG (*((volatile Register_t *)0xFD5))
    #define T1CON_REG (*((volatile Register_t *)0xFCD))
    #define T2CON_REG (*((volatile Register_t *)0xFCA))
    #define T3CON_REG (*((volatile Register_t *)0xFB1))
/*---------------------OSCCON_REG------------------------*/
    #define OSCCON_REG (*((volatile Register_t *)0xFD3))
/*---------------------HLVDCON_REG------------------------*/
    #define HLVDCON_REG (*((volatile Register_t *)0xFD2))
/*---------------------WDTCON_REG------------------------*/
    #define WDTCON_REG (*((volatile Register_t *)0xFD1))
/*---------------------RCON_REG------------------------*/
    #define RCON_REG (*((volatile Register_t *)0xFD0))

/*---------------------PR2_REG------------------------*/
    #define PR2_REG (*((volatile Register_t *)0xFCB))
/*---------------------T2CON_REG------------------------*/
    #define T2CON_REG (*((volatile Register_t *)0xFCA))
/*---------------------SSPBUF_REG------------------------*/
    #define SSPBUF_REG (*((volatile Register_t *)0xFC9))
/*---------------------SSPADD_REG------------------------*/
    #define SSPADD_REG (*((volatile Register_t *)0xFC8))
/*---------------------SSPSTAT_REG------------------------*/
   #define SSPSTAT_REG (*((volatile Register_t *)0xFC7))
/*---------------------SSPCON_REG------------------------*/
    #define SSPCON1_REG (*((volatile Register_t *)0xFC6))
    #define SSPCON2_REG (*((volatile Register_t *)0xFC5))
/*---------------------ADRES_REG------------------------*/
    #define ADRESH_REG (*((volatile Register_t *)0xFC4))
    #define ADRESL_REG (*((volatile Register_t *)0xFC3))
/*---------------------ADCON_REG------------------------*/
    #define ADCON0_REG (*((volatile Register_t *)0xFC2))
    #define ADCON1_REG (*((volatile Register_t *)0xFC1))
    #define ADCON2_REG (*((volatile Register_t *)0xFC0))
/*---------------------CCPR_REG------------------------*/
    #define CCPR1H_REG (*((volatile Register_t *)0xFBF))
    #define CCPR1L_REG (*((volatile Register_t *)0xFBE))
    #define CCPR2H_REG (*((volatile Register_t *)0xFBC))
    #define CCPR2L_REG (*((volatile Register_t *)0xFBB))
/*---------------------CCPCON_REG------------------------*/
    #define CCP1CON_REG (*((volatile Register_t *)0xFBD))
    #define CCP2CON_REG (*((volatile Register_t *)0xFBA))
/*---------------------BAUDCON_REG------------------------*/
    #define BAUDCON_REG (*((volatile Register_t *)0xFB8))
/*---------------------PWM1CON_REG------------------------*/
    #define PWM1CON_REG (*((volatile Register_t *)0xFB7))
/*---------------------ECCP1AS_REG------------------------*/
    #define ECCP1AS_REG (*((volatile Register_t *)0xFB6))
/*---------------------CVRCON_REG------------------------*/
    #define CVRCON_REG (*((volatile Register_t *)0xFB5))
/*---------------------CMCON_REG------------------------*/
    #define CMCON_REG (*((volatile Register_t *)0xFB4))
/*---------------------SPBRG_REG------------------------*/
    #define SPBRG_REG (*((volatile Register_t *)0xFAF))
    #define SPBRGH_REG (*((volatile Register_t *)0xFB0))

/*---------------------RCREG_REG------------------------*/
    #define RCREG_REG (*((volatile Register_t *)0xFAE))
    #define RCSTA_REG (*((volatile Register_t *)0xFAB))
/*---------------------TX_REG------------------------*/
    #define TXREG_REG (*((volatile Register_t *)0xFAD))
    #define TXSTA_REG (*((volatile Register_t *)0xFAC))

/*---------------------EEADR_REG------------------------*/
    #define EEADR_REG (*((volatile Register_t *)0xFA9))
    #define EEADRH_REG (*((volatile Register_t *)0xFAA))
/*---------------------EEDATA_REG------------------------*/
    #define EEDATA_REG (*((volatile Register_t *)0xFA8))
/*---------------------EECON_REG------------------------*/
    #define EECON1_REG (*((volatile Register_t *)0xFA6))
    #define EECON2_REG (*((volatile Register_t *)0xF82))
/*---------------------IPR_REG------------------------*/
    #define IPR1_REG (*((volatile Register_t *)0xF9F))
    #define IPR2_REG (*((volatile Register_t *)0xFA2))
/*---------------------PIR_REG------------------------*/
    #define PIR1_REG (*((volatile Register_t *)0xF9E))
    #define PIR2_REG (*((volatile Register_t *)0xFA1))
/*---------------------PIE_REG------------------------*/
    #define PIE1_REG (*((volatile Register_t *)0xF9D))
    #define PIE2_REG (*((volatile Register_t *)0xFA0))
/*---------------------OSCTUNE_REG------------------------*/
    #define OSCTUNE_REG (*((volatile Register_t *)0xF9B))
/*---------------------LAT_REG------------------------*/
    #define LATA_REG (*((volatile Register_t *)0xF89))
    #define LATB_REG (*((volatile Register_t *)0xF8A))
    #define LATC_REG (*((volatile Register_t *)0xF8B))
    #define LATD_REG (*((volatile Register_t *)0xF8C))
    #define LATE_REG (*((volatile Register_t *)0xF8D))


#endif

#define SET_BIT(REG,BIT) (REG |= (1 << BIT))
#define CLEAR_BIT(REG,BIT) (REG &= ~(1 << BIT))
#define TOGGEL_BIT(REG,BIT) (REG ^= (1 << BIT))
#define IS_SET(REG,BIT) (REG &= (1 << BIT))
#define SET_REG(REG) (REG |= (255 << START_BIT))
#define CLEAR_REG(REG) (REG &= ~(255 << START_BIT))
#define TOGGEL_REG(REG) (REG ^= (255 << START_BIT))

#endif