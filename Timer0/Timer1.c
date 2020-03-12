#include "timer.h"

void main() {
  TRISC_REG.Register = 0;
  RC0_bit = 0;
  timer0_init();
  timer0_on();
}