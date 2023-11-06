/* 
 * File:   Mcal_Initialize.h
 * Author: AMMAR Yasser
 *
 * Created on 03/10/2023
 */

#ifndef MCAL_INITIALIZE_H
#define	MCAL_INITIALIZE_H

/******Includes**********/

#include "Interrupt/mcal_Interrupt_manger.h"
#include "Interrupt/mcal_external_Interrupt.h"
#include "Interrupt/mcal_internal_Interrupt.h"
#include "device_config.h"
#include "EEPROM/hal_eeprom.h"
#include "ADC/hall_ADC.h"
#include "Timer0/Timer0.h"
#include "Timer1/Timer1.h"
#include "Timer2/Timer2.h"
#include "Timer3/Timer3.h"
#include "CCP/CCP1.h"
#include "Uart/uart.h"
/*********Macro Declaration***********/

/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/

extern volatile uint8 counter1;
extern volatile uint8 counter2;
extern volatile uint8 flag;
extern volatile uint8 flag2;



/*********Function Declaration***********/

#endif	/* MCAL_INITIALIZE_H */

