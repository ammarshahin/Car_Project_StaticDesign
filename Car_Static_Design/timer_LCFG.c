/*
 * timer_PCFG.c
 *
 * Created: 11/4/2019 2:04:00 PM
 *  Author: Ammar Shahin
 */ 

#include "registers_ATmega32.h"
#include "timer_LCFG.h"

#define Counter_Default 20000

Timer_CFG_S cfg_s = {
    TIMER0,
    TIMER_MODE,
    Counter_Default,
    INTERRUPT,
    F_CPU,
}; 