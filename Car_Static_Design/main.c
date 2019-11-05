/*
 * Car_Static_Design.c
 *
 * Created: 11/5/2019 12:29:26 PM
 * Author : AVE-LAP-44
 */ 

#include "Car_Control.h"

int main(void)
{
	Car_Init();
    while (1) 
    {
		Car_Action();
    }
}

