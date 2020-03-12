#include "timer.h"

void main() {
  TRISC_REG.Register = 0;
  RC0_bit = 0;
  timer1_init();
  timer1_on();
}