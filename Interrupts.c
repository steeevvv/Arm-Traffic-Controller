#include "tm4c123gh6pm.h"
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
#include "Gpio.h"
#include "Timer.h"
#include "Interrupts.h"

void FSM (void)
{
    //Traffic Lights States
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    counter = 0;
    if(state == 0){
      state_1();
      delay_s (2, TIMER0_BASE);
      state++;
    }
    else if (state == 1) //PEDESTRIAN NORTH SOUTH
    {
      state_2();
      delay_s (1, TIMER0_BASE);
      state++; 
    }
    else if (state == 2) //CARS EAST WEST
    {
      state_3();
      delay_s (5, TIMER0_BASE);
      state++;     
    }
    else if (state == 3)
    {
      state_4();
      delay_s (2, TIMER0_BASE);
      state++;     
    }
    else if(state == 4) //PEDESTRAIN EAST-WEST
    {
      state_5();
      delay_s (1, TIMER0_BASE);
      state++;    
    }
    else if (state == 5) {
      state_0();
      delay_s (5, TIMER0_BASE);
      state=0;    
    }
}

void FSM2 (void){
    if (counter < 1){
      if(GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_6) == GPIO_PIN_6){
          GPIOIntClear(GPIO_PORTD_BASE, GPIO_INT_PIN_6);
          GPIOIntClear(GPIO_PORTD_BASE, GPIO_INT_PIN_7);
          if (state ==3){
            if (TimerValueGet(TIMER0_BASE,TIMER_A) >= 63999999){
              while (TimerValueGet(TIMER0_BASE,TIMER_A) >= 63999999){};
            }
            TimerDisable(TIMER0_BASE, TIMER_A);
            Button_1();          
          }          
          else {
              return;
          } 
      }
    else {
          GPIOIntClear(GPIO_PORTD_BASE, GPIO_INT_PIN_6);
          GPIOIntClear(GPIO_PORTD_BASE, GPIO_INT_PIN_7);
        if (state ==0){
            if (TimerValueGet(TIMER0_BASE,TIMER_A) >= 63999999){
              while (TimerValueGet(TIMER0_BASE,TIMER_A) >= 63999999);
          }
        TimerDisable(TIMER0_BASE, TIMER_A);
        Button_2();
        }
        else {
             TimerEnable(TIMER0_BASE, TIMER_A);
             return;
         }
    }
    delay_s(2, TIMER1_BASE);
    counter++;
   }
   else{
         GPIOIntClear(GPIO_PORTD_BASE, GPIO_INT_PIN_7);
         GPIOIntClear(GPIO_PORTD_BASE, GPIO_INT_PIN_6);
   }
}

void TimerInt(void){
  TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
  if (state ==0) {
    state_0();
  }
    else if(state ==3) {
    state_3();
    }
  TimerEnable(TIMER0_BASE, TIMER_A);
  return;
}