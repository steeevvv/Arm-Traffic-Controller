#include "stdint.h"
#include "stdbool.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "tm4c123gh6pm.h"
#include "Timer.h"
#include "Gpio.h"
#include "states.h"
#include "Interrupts.h"

void main(void)
{
  IntPrioritySet(INT_GPIOD, 0x20);
  IntPrioritySet(INT_TIMER0A, 0x40);

    //System Initialization
    Timer0Init ();
    portDInit ();
    Timer1Init ();
    portAInit ();
    state_0();
    delay_s (5, TIMER0_BASE);
    while(1)
    {}
}
  
