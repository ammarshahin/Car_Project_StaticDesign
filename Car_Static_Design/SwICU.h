/*
 * icu.h
 *
 * Created: 11/5/2019 12:29:51 PM
 *  Author: AVE-LAP-025
 */ 
/***************************************************************************************
 *									 Documentation
 ***************************************************************************************
 *	- This Module uses Timer 0 and INT 0
 *	
 */

#ifndef ICU_H_
#define ICU_H_

#include "t_typedef.h"

/*
 * Description: This function initializes the ICU module 
 * Parameter: void
 * Return : void
 */
uint8 SwICU_Init(void);
/*
 * Description:This function Reads all Timer 0 counts (Including overflow ) 
 * Parameter: void
 * Return : Reading value
 */
uint8 SwICU_Read(uint64* Reading_value);
/*
 * Description:
 * This function enables the ICU functionality 
 * Parameter: void
 * Return : Reading value
 */
uint8 SwICU_Enable(void);
/*
 * Description:
 * This function disables the ICU functionality
 * Parameter: void
 * Return : Reading value
 */
uint8 SwICU_Disable(void);



#endif /* ICU_H_ */