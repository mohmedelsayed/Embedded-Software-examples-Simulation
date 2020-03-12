#include "reg.h"
#define ON (1)
#define OFF (0)
#define LED0 PORTC_REG.Register_Bits.Bit0
#define LED1 PORTC_REG.Register_Bits.Bit4


typedef enum{

   PRIORITY_ENABLE,        // RCON ==>bit7 = 1
   PRIORITY_DISABLE        // RCON ==>bit7 = 0

}priority_state;

typedef enum{

   HIGH_PRIORITY,        // INTCON ==>bit7 = 1
   LOW_PRIORITY          // INTCON ==>bit6 = 1

}interrupt_Type;








void interrupt_init( void );
void interrupt(void);