#include "tm4c123gh6pm.h"

extern int counter;
extern int state;

// Traffic Lights Timer Initialization
void Timer0Init (void);

//Delay function that takes timer base, and amount of delay in s
void delay_s (uint32_t delay, uint32_t base);

// Pedestrians Timer when a button is pushed
void Timer1Init ();