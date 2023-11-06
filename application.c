/* 
 * 
 * File:   application.c
 * Author: Ammar.Yasser
 *
 * Created on 21 ?????, 2023, 06:12 ?
 */

#include "application.h"
#include "MCAL_layer/SPI/spi.h"

Std_ReturnType ret = E_NOT_OK;
volatile uint8 counter1 = 0;
volatile uint8 counter2 = 2;
volatile uint8 flag     = 0;
volatile uint8 flag2 =0 ;


int main() {
    
    application_initialize();
    ret = seven_segment_write_number(&seg_1,counter2);
    ret = seven_segment_write_number(&seg_2,counter1);
    ret = led_turn_on(&led1);
    ret = led_turn_on(&led6);
    ret = lcd_8bit_send_string_pos(&lcd_1,2,6,"Cars Move");
    while(1)
    {
        if(flag == 1)
        {
            ret = seven_segment_write_number(&seg_1,counter2);
            ret = seven_segment_write_number(&seg_2,counter1); 
            flag = 0;
            if((counter1 == 5)&&(counter2 == 0))
            {
                ret = lcd_8bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                ret = lcd_8bit_send_string_pos(&lcd_1,2,6,"Harry Up!!");
                ret = led_turn_on(&led2);
                ret = led_turn_on(&led5);
                ret = led_turn_off(&led1);
                ret = led_turn_off(&led3);
                ret = led_turn_off(&led4);
                ret = led_turn_off(&led6);

            }
        }
        else if(flag == 2)
        {
            ret = seven_segment_write_number(&seg_1,counter2);
            ret = seven_segment_write_number(&seg_2,counter1);
            ret = led_turn_off(&led2);
            ret = led_turn_off(&led5);
            if(flag2 == 0)
            {
                ret = lcd_8bit_send_string_pos(&lcd_1,2,4,"Pedestrian Move");
                ret = led_turn_off(&led1);
                ret = led_turn_off(&led6);
                ret = led_turn_on(&led3);
                ret = led_turn_on(&led4);
                flag2 = 1;
            }
            else
            {
                ret = lcd_8bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                ret = lcd_8bit_send_string_pos(&lcd_1,2,6,"Cars Move");
                ret = led_turn_on(&led1);
                ret = led_turn_on(&led6);
                ret = led_turn_off(&led3);
                ret = led_turn_off(&led4);
                flag2 = 0;
            }
            
            flag = 0;
        }
        
    }
    return (0);
}

void application_initialize (void)
{
    ecu_initialize();
    Mcal_initialize();
}
