/*
 * Car_Control.c
 *
 * Created: 11/5/2019 1:51:29 PM
 *  Author: Ammar Shahin
 */ 
#include "t_typedef.h"
#include "DC_Motor.h"
#include "Ultrasonic.h"
#include "Dir_Control.h"
#include "Car_Control.h"
#include "registers_ATmega32.h"
#include <util/delay.h>

void Car_Init(void)
{
	DC_Motor_Init(DC_Motor_Channel_0);
	DC_Motor_Init(DC_Motor_Channel_1);
	initializeUltraSonic();
	DC_Motor_Start(DC_Motor_Channel_0);
	DC_Motor_Start(DC_Motor_Channel_1);
}


void Car_Action(void)
{
	uint8 distance = 200;
	triggerUltrasonic();
	distance = calculateDistance();
	if(distance > 60)
	{
		move_Forward();
		DC_Motor_Set_Speed(95);
	}	
	else if ( (distance < 60) && (distance > 30) )
	{
		move_RotateRight();
		DC_Motor_Set_Speed(50);
		_delay_ms(100);
	}
	else if(distance < 30)
	{
		DC_Motor_Set_Speed(30);
		move_Backward();
		_delay_ms(100);
	}
}