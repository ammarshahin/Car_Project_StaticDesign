/*
 * SwICU.c
 *
 * Created: 11/5/2019 2:44:26 PM
 *  Author: Ammar Shahin
 */ 

#include "t_typedef.h"
#include "timers.h"
#include "gpio.h"
#include "interrupt_Lib.h"

volatile uint8 flag = 0,numOfOverflows = 0;
volatile uint64 raising_time_ns = 0;


/*
 * Description: This function initializes the ICU module 
 * Parameter: void
 * Return : void
 */
uint8 SwICU_Init(void)
{
	INT0_Init_anyChange();
	Av_timer2Init(T2_NORMAL_MODE,T2_OC0_DIS,T2_PRESCALER_1,0,0,T2_INTERRUPT_NORMAL);
	interrupts_On();
	return OK;
}
/*
 * Description:	This function Reads all Timer 0 counts (Including overflow ) 
 * Parameter:	 void
 * Return :		Reading value
 */
uint8 SwICU_Read(uint64* Reading_value)
{
	*Reading_value = raising_time_ns;
	return OK;
}
/*
 * Description:
 * This function enables the ICU functionality 
 * Parameter: void
 * Return : Reading value
 */
uint8 SwICU_Enable(void)
{
	interrupts_On();
	return OK;
}
/*
 * Description:
 * This function disables the ICU functionality
 * Parameter: void
 * Return : Reading value
 */
uint8 SwICU_Disable(void)
{
	Av_timer2Stop();
	return OK;
}


t_ISR(INT0_vect)
{
	if(flag == 0)
	{
		TCNT2 = 0;
		Av_timer2Start();
		numOfOverflows = 0;
		flag = 1;
	}
	else if(flag == 1)
	{
		raising_time_ns =  ( ( (numOfOverflows * 256) + TCNT2 ) * ( 1000000000/F_CPU ) );
		Av_timer1Stop();
		numOfOverflows = 0;
		TCNT2 = 0;
		flag = 0;
	}
}


t_ISR(TIMER2_OVF_vect)
{
	numOfOverflows++;
}