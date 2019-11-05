/*
 * Dir_control.c
 *
 * Created: 11/5/2019 12:42:44 PM
 *  Author: Ammar Shahin
 */

#include "DC_Motor.h"
#include "DC_Motor_cfg.h"

void move_Forward(void)
{
	DC_Motor_Set_Direction(DC_Motor_Channel_0, DC_Motor_Forward);
	DC_Motor_Set_Direction(DC_Motor_Channel_1, DC_Motor_Forward);
}
void move_Backward(void)
{
	DC_Motor_Set_Direction(DC_Motor_Channel_0, DC_Motor_Back);
	DC_Motor_Set_Direction(DC_Motor_Channel_1, DC_Motor_Back);
}

void move_RotateRight(void)
{
	DC_Motor_Set_Direction(DC_Motor_Channel_0, DC_Motor_Back);
	DC_Motor_Set_Direction(DC_Motor_Channel_1, DC_Motor_Forward);
}
void move_RotateLeft(void)
{
	DC_Motor_Set_Direction(DC_Motor_Channel_0, DC_Motor_Forward);
	DC_Motor_Set_Direction(DC_Motor_Channel_1, DC_Motor_Back);
}
void Stop(void)
{
	DC_Motor_Stop(DC_Motor_Channel_0);
	DC_Motor_Stop(DC_Motor_Channel_1);
}
