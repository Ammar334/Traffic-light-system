/* 
 * File:   Mcal_Initialize.h
 * Author: AMMAR Yasser
 *
 * Created on 03/10/2023
 */


#include "Mcal_Initialize.h"

void INT0_interrubt (void);
void timer0_interrubt (void);


TIMER0_t tm0 = {
    .Timer0CallBack = timer0_interrubt,
    .Timer0_MODE = TIMER0_TIMER_MODE,
    .Timer0_register_size = TIMER0_16BIT_SIZE,
    .prescaler_Enable = TIMER0_PRESCALER_ENABLE_CFG,
    .prescaler_value = TIMER0_prescaler_Div_16,
    .timer0_preload_value = 3036
};

Intterupt_INTx_t int0 =
{
    .INTx_CallBack = INT0_interrubt,
    .edge = RISING_EDGE,
    .index = EXT_INT0,
    .pin.direction = GPIO_INPUT,
    .pin.logic = GPIO_LOW,
    .pin.pin = GPIO_PIN0,
    .pin.port = GPIO_PORT_B
    
};




void Mcal_initialize (void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = Interrupt_INTx_Init(&int0);
    ret = Timer0_init(&tm0);
    
}

void INT0_interrubt (void)
{
    flag = 2;
    flag2 = 0;
    counter2 = 2;
    counter1 = 0;
    Timer0_Write_Value(&tm0,3036);
}

void timer0_interrubt (void)
{
    if(counter1 == 0)
    {
        counter1 = 9;
        flag = 1;
        if(counter2 != 0)
        {
            counter2--;
        }
        else
        {
            flag = 2;
            counter2 = 2;
            counter1 = 0;
        }
    }
    else
    {
        flag = 1;
        counter1--;
    }
}
