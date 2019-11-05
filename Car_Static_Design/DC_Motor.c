/*
 * DC_Motor.c
 *
 * Created: 11/5/2019 1:06:51 PM
 *  Author: AVE-LAP-44
 */ 

#include "t_typedef.h"
#include "gpio.h"
#include "timers.h"
#include "DC_Motor_cfg.h"
#include "DC_Motor.h"

#define Motor_Frequency_in_Hz 500


void DC_Motor_Init(uint8 Channel)
{
	Av_timer1Init(T1_PWM_PhaseCorrect_ICR1_MODE,T1_OC1A_CLEAR,T1_PRESCALER_1024,0,0,0,0,T1_POLLING);
	switch(Channel)
	{
		case DC_Motor_Channel_0 : 
					/* Initiate the Motor pin Direction */
					Av_gpioPinDirection(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,set_OUT);
					Av_gpioPinDirection(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,set_OUT);
	
					/* Initiate the Motor pin  */
					Av_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,LOW);
					Av_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,LOW);
		break;
		case DC_Motor_Channel_1 : 
					/* Initiate the Motor pin Direction */
					Av_gpioPinDirection(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,set_OUT);
					Av_gpioPinDirection(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,set_OUT);
		
					/* Initiate the Motor pin  */
					Av_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,LOW);
					Av_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,LOW);
		break;
		default:
		break;
	}
}


uint8 DC_Motor_Set_Speed(uint8 Speed)
{
	if(Speed <= 100)
	{
		Av_timer1PWM(Speed,Motor_Frequency_in_Hz);
		return OK;
	}
	else
	{
		return NOT_OK;
	}
}


uint8 DC_Motor_Set_Direction(uint8 Channel , uint8 Direction)
{
	switch(Channel)
	{
		case DC_Motor_Channel_0 :
			switch(Direction)
			{
				case DC_Motor_Forward :
						/* Set the Motor pin */
						Av_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,HIGH);
						Av_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,LOW);
				break;
				case DC_Motor_Back : 
						/* Set the Motor pin */
						Av_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,LOW);
						Av_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,HIGH);
				break;
				default:
				break;
			}
		break;
		case DC_Motor_Channel_1 :
			switch(Direction)
			{
				case DC_Motor_Forward :
					/* Set the Motor pin */
					Av_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,HIGH);
					Av_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,LOW);
				break;
				case DC_Motor_Back :
					/* Set the Motor pin */
					Av_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,LOW);
					Av_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,HIGH);
				break;
				default:
				break;
		}
		break;
	}
	return OK;
}


void DC_Motor_Stop(uint8 Channel)
{
	switch(Channel)
	{
		case DC_Motor_Channel_0 : 
		Av_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,LOW);
		Av_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,LOW);
		break;
		case DC_Motor_Channel_1 : 
		Av_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,LOW);
		Av_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,LOW);
		break;
		default:
		break;	
	}		
}


void DC_Motor_Start(uint8 Channel)
{
	DC_Motor_Set_Speed(50); // 50 As a default speed
	Av_timer1Start();
	DC_Motor_Set_Direction(Channel,DC_Motor_Forward); // Move Forward as A default Direction
}