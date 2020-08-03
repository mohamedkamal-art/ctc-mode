/*
 * Session_6(Timer_0_CTC_Mode).c
 *
 * Created: 8/2/2020 9:28:13 PM
 * Author : mohammed
 */ 

//#include <avr/io.h>
#include "Timer.h"
#include <avr/interrupt.h>


extern  uint32 Num_Com_Match;

int main(void)
{
	LED0_Init();
	LED0_ON();
	
    Timer_Init();
	Timer_SetDelay(1000);
	Timer_Start();
	
    while (1) 
    {
		
    }
}

ISR(TIMER0_COMP_vect)
{
	static uint32 count = 0;
	
	count++;
	
	if (count == Num_Com_Match)
	{
		LED0_toggle();
		count = 0;
	}
}




