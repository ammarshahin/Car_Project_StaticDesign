/*
 * Ultrasonic.c
 *
 * Created: 11/5/2019 2:20:05 PM
 *  Author: Ammar Shahin
 */ 
#include "gpio.h"
#include "SwICU.h"
#include "Ultrasonic_Cfg.h"
#include "Ultrasonic.h"
#include "util/delay.h"


void initializeUltraSonic(void)
{
	SwICU_Init();
	Av_gpioPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,set_OUT);
	Av_gpioPinDirection(ULTRASONIC_ECHO_PORT,ULTRASONIC_ECHO_PIN,set_IN);
}

void triggerUltrasonic(void)
{
	Av_gpioPinWrite(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,HIGH);
	_delay_us(10);
	Av_gpioPinWrite(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,LOW);
}

uint32 calculateDistance(void)
{
	uint32 theDistance;
	uint64 raising_time_ns;
	SwICU_Read(&raising_time_ns);
	theDistance = ( (raising_time_ns/1000000000.0) * (34300/2) );
	return theDistance;	
}