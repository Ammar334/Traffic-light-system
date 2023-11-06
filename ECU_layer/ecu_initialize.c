/* 
 * File:   ecu_initialize.h
 * Author: ammar.yasser
 *
 * Created on 06 ?????, 2023, 05:59 ?
 */

#include "ecu_initialize.h"

lcd_8bit_t lcd_1 = {
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_rs.pin = GPIO_PIN0,
    .lcd_rs.port = GPIO_PORT_A,
    .lcd_enable.direction = GPIO_OUTPUT,
    .lcd_enable.logic = GPIO_LOW,
    .lcd_enable.pin = GPIO_PIN1,
    .lcd_enable.port = GPIO_PORT_A,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[0].pin = GPIO_PIN0,
    .lcd_data[0].port = GPIO_PORT_D,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[1].pin = GPIO_PIN1,
    .lcd_data[1].port = GPIO_PORT_D,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[2].pin = GPIO_PIN2,
    .lcd_data[2].port = GPIO_PORT_D,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
    .lcd_data[3].pin = GPIO_PIN3,
    .lcd_data[3].port = GPIO_PORT_D,
    .lcd_data[4].direction = GPIO_OUTPUT,
    .lcd_data[4].logic = GPIO_LOW,
    .lcd_data[4].pin = GPIO_PIN4,
    .lcd_data[4].port = GPIO_PORT_D,
    .lcd_data[5].direction = GPIO_OUTPUT,
    .lcd_data[5].logic = GPIO_LOW,
    .lcd_data[5].pin = GPIO_PIN5,
    .lcd_data[5].port = GPIO_PORT_D,
    .lcd_data[6].direction = GPIO_OUTPUT,
    .lcd_data[6].logic = GPIO_LOW,
    .lcd_data[6].pin = GPIO_PIN6,
    .lcd_data[6].port = GPIO_PORT_D,
    .lcd_data[7].direction = GPIO_OUTPUT,
    .lcd_data[7].logic = GPIO_LOW,
    .lcd_data[7].pin = GPIO_PIN7,
    .lcd_data[7].port = GPIO_PORT_D
    
};

dc_motor_t motor_1 = {
  
    .dc_motor_pin[0].direction = GPIO_OUTPUT,
    .dc_motor_pin[0].logic = GPIO_LOW,
    .dc_motor_pin[0].pin = GPIO_PIN2,
    .dc_motor_pin[0].port = GPIO_PORT_C,
    .dc_motor_pin[1].direction = GPIO_OUTPUT,
    .dc_motor_pin[1].logic = GPIO_LOW,
    .dc_motor_pin[1].pin = GPIO_PIN3,
    .dc_motor_pin[1].port = GPIO_PORT_C,
    
};

dc_motor_t motor_2 = {
  
    .dc_motor_pin[0].direction = GPIO_OUTPUT,
    .dc_motor_pin[0].logic = GPIO_LOW,
    .dc_motor_pin[0].pin = GPIO_PIN4,
    .dc_motor_pin[0].port = GPIO_PORT_C,
    .dc_motor_pin[1].direction = GPIO_OUTPUT,
    .dc_motor_pin[1].logic = GPIO_LOW,
    .dc_motor_pin[1].pin = GPIO_PIN5,
    .dc_motor_pin[1].port = GPIO_PORT_C,
    
};

button_t btn_1 = {
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_pin.direction = GPIO_INPUT,
    .button_pin.logic = GPIO_LOW,
    .button_pin.pin = GPIO_PIN0,
    .button_pin.port=GPIO_PORT_B,
    .button_st = BUTTON_RELESED
};
segment_t seg_1={
    .segment[0].direction = GPIO_OUTPUT,
    .segment[0].logic = GPIO_LOW,
    .segment[0].pin = GPIO_PIN0,
    .segment[0].port = GPIO_PORT_C,
    .segment[1].direction = GPIO_OUTPUT,
    .segment[1].logic = GPIO_LOW,
    .segment[1].pin = GPIO_PIN1,
    .segment[1].port = GPIO_PORT_C,
    .segment[2].direction = GPIO_OUTPUT,
    .segment[2].logic = GPIO_LOW,
    .segment[2].pin = GPIO_PIN2,
    .segment[2].port = GPIO_PORT_C,
    .segment[3].direction = GPIO_OUTPUT,
    .segment[3].logic = GPIO_LOW,
    .segment[3].pin = GPIO_PIN3,
    .segment[3].port = GPIO_PORT_C,
};
segment_t seg_2={
    .segment[0].direction = GPIO_OUTPUT,
    .segment[0].logic = GPIO_LOW,
    .segment[0].pin = GPIO_PIN4,
    .segment[0].port = GPIO_PORT_C,
    .segment[1].direction = GPIO_OUTPUT,
    .segment[1].logic = GPIO_LOW,
    .segment[1].pin = GPIO_PIN5,
    .segment[1].port = GPIO_PORT_C,
    .segment[2].direction = GPIO_OUTPUT,
    .segment[2].logic = GPIO_LOW,
    .segment[2].pin = GPIO_PIN6,
    .segment[2].port = GPIO_PORT_C,
    .segment[3].direction = GPIO_OUTPUT,
    .segment[3].logic = GPIO_LOW,
    .segment[3].pin = GPIO_PIN7,
    .segment[3].port = GPIO_PORT_C,
};

led_t led1 = {.port_name = GPIO_PORT_A, .pin_number = GPIO_PIN2, .pin_statues = GPIO_LOW};
led_t led2 = {.port_name = GPIO_PORT_A, .pin_number = GPIO_PIN3, .pin_statues = GPIO_LOW};
led_t led3 = {.port_name = GPIO_PORT_B, .pin_number = GPIO_PIN2, .pin_statues = GPIO_LOW};
led_t led4 = {.port_name = GPIO_PORT_A, .pin_number = GPIO_PIN5, .pin_statues = GPIO_LOW};
led_t led5 = {.port_name = GPIO_PORT_A, .pin_number = GPIO_PIN6, .pin_statues = GPIO_LOW};
led_t led6 = {.port_name = GPIO_PORT_B, .pin_number = GPIO_PIN1, .pin_statues = GPIO_LOW};


void ecu_initialize (void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = led_initialize(&led1);
    ret = led_initialize(&led2);
    ret = led_initialize(&led3);
    ret = led_initialize(&led4);
    ret = led_initialize(&led5);
    ret = led_initialize(&led6);
    ret = lcd_8bit_initialize(&lcd_1);
    ret = initialize_seven_segment(&seg_1);
    ret = initialize_seven_segment(&seg_2);
    ret = push_button_initialize(&btn_1);


}