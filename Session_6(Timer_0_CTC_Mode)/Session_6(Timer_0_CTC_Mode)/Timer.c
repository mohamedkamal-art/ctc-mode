/*
 * Timer.c
 *
 * Created: 17/07/2020 12:28:31 م
 *  Author: Ali
 */ 


#include "Timer.h"
#include "BIT_Math.h"


 
 uint32 Num_Com_Match= 0;


void Timer_Init(void)
{
	/*Initilize Timer 0  as CTC mode */
	SET_BIT(TCCR0 , 3);
	CLR_BIT(TCCR0 , 6);
	// enable peripheral Timer INT
	TIMSK |= 0x01;
	// enable general INT GIE
	SREG |= 0x80;
	
}

void Timer_Start(void)
{
	
	/* start timer with prescaler   1024 */
	TCCR0 |= 0x05;
	
}

void Timer_Stop(void)
{
	
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	
}


void Timer_SetDelay(uint32 Delay_Ms)
{
	/* tick time in micro second */
	uint8 Tick_Time_us = (1024 / 16);
	
	uint32 Total_Ticks = (Delay_Ms * 1000) / Tick_Time_us;
	
	OCR0 = Total_Ticks - 1;
	
	// when counter register complete take 16 ms 
	if (Delay_Ms > 16)
	{
		Num_Com_Match = 1;
	}
	else
	{ 
		Num_Com_Match = 16 / Delay_Ms;
	}
	
	
	
	
}

