/* 
 * File:   applications.h
 * Author: Ammar.Yasser
 *
 * Created on 21 ?????, 2023, 06:18 ?
 */

#ifndef APPLICATIONS_H
#define	APPLICATIONS_H


/******Includes**********/
#include "ECU_layer/ecu_initialize.h"
#include "MCAL_layer/Mcal_Initialize.h"


/*********Macro Declaration***********/

/*********Macro Function Declaration***********/
/*********Data Types Declaration***********/
extern lcd_8bit_t lcd_1; 
extern button_t btn_1;
extern segment_t seg_1;
extern segment_t seg_2;
extern led_t led1;
extern led_t led2;
extern led_t led3;
extern led_t led4;
extern led_t led5;
extern led_t led6;




        
/*********Function Declaration***********/
void application_initialize (void);
void ecu_initialize (void);
void Mcal_initialize(void);

#endif	/* APPLICATIONS_H */

