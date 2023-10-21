//
// Created by YINING on 2023/10/21.
//

#include "led.h"
led::led(const char *str){
    strcpy(name,str);
}
void led::LED_Flash()//”√ ±1000ms
{
    if(strcmp(name, "LED1") == 0)
    {
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_12);
        HAL_Delay(500);
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_12);
        HAL_Delay(500);
    }
    else if(strcmp(name, "LED2") == 0)
    {
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
        HAL_Delay(500);
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
        HAL_Delay(500);
    }
}

