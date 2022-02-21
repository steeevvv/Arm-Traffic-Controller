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
#include "Timer.h"
#include "Interrupts.h"

 int counter = 0;
 int state=0;



void Timer0Init (void){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0)){}
  TimerClockSourceSet(TIMER0_BASE,TIMER_CLOCK_SYSTEM);
  
  TimerDisable(TIMER0_BASE, TIMER_A);
  TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
  TimerIntRegister(TIMER0_BASE, TIMER_A, FSM);
  TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

  TimerEnable(TIMER0_BASE, TIMER_A);
}

void Timer1Init (){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER1)){}
  TimerClockSourceSet(TIMER1_BASE,TIMER_CLOCK_SYSTEM);
  
  TimerDisable(TIMER1_BASE, TIMER_A);
  TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC);
  TimerIntRegister(TIMER1_BASE, TIMER_A, TimerInt);
  TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
  
  TimerEnable(TIMER1_BASE, TIMER_A);
 }


void delay_s (uint32_t delay, uint32_t base) {
    TimerLoadSet(base, TIMER_A, (16000000*delay)-1);
    TimerEnable(base, TIMER_A);
}

