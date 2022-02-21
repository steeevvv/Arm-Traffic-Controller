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
#include "states.h"
#include "Timer.h"
#include "Interrupts.h"


void clear(void){
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_2,0);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_3,0);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_4,0);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_5,0);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_6,0);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_7,0);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_0,0);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_1,0);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_2,0);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_3,0);
}

void state_0 (void)
{
      clear();
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_4,GPIO_PIN_4);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_5,GPIO_PIN_5);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_3,GPIO_PIN_3);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_0,GPIO_PIN_0);
}


void state_1 (void)
{
      clear();
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_3,GPIO_PIN_3);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_5,GPIO_PIN_5);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_3,GPIO_PIN_3);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_0,GPIO_PIN_0);

}

void state_2 (void)
{
      clear();
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_2,GPIO_PIN_2);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_5,GPIO_PIN_5);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_3,GPIO_PIN_3);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_1,GPIO_PIN_1);

}

void state_3 (void)
{
      clear(); 
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_2,GPIO_PIN_2);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_7,GPIO_PIN_7);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_2,GPIO_PIN_2);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_1,GPIO_PIN_1);

}

void state_4 (void)
{
      clear(); 
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_2,GPIO_PIN_2);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_6,GPIO_PIN_6);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_2,GPIO_PIN_2);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_1,GPIO_PIN_1);
}

void state_5 (void)
{
      clear();
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_2,GPIO_PIN_2);
      GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_5,GPIO_PIN_5);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_3,GPIO_PIN_3);
      GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_1,GPIO_PIN_1);
}

void Button_1(void){
          GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_7,0);
          GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_5,GPIO_PIN_5);
          GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_3,GPIO_PIN_3);
          GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_2,0);
}

void Button_2(void){
        GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_4,0);
        GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PIN_2,GPIO_PIN_2);
        GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_0,0);
        GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_1,GPIO_PIN_1);
}


