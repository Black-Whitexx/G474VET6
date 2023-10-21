//
// Created by YINING on 2023/10/21.
//

#include "Mymain.h"
#include "fdcan.h"
#include "gpio.h"

led LED1("LED1");
led LED2("LED2");
Myfdcan FDCan1(&hfdcan1);
Myfdcan FDCan2(&hfdcan2);
Myfdcan FDCan3(&hfdcan3);
uint8_t mes[] = {0x11, 0x22, 0x33};
void Mymain(){
    while(1){
        FDCan1.CanFilter_Normal_Init(0x0000, 0x0000);
        FDCan1.Can_Start();
        FDCan1.Can_SendMessage(mes, sizeof(mes), 0x122);
        LED1.LED_Flash();
        FDCan2.CanFilter_Normal_Init(0x0001, 0x0000);
        FDCan2.Can_Start();
        FDCan2.Can_SendMessage(mes, sizeof(mes), 0x122);
        LED1.LED_Flash();
        FDCan3.CanFilter_Normal_Init(0x0002, 0x0000);
        FDCan3.Can_Start();
        FDCan3.Can_SendMessage(mes, sizeof(mes), 0x122);
        LED2.LED_Flash();
}
}