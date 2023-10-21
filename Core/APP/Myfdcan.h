//
// Created by YINING on 2023/10/21.
//

#ifndef BLINKE_MYFDCAN_H
#define BLINKE_MYFDCAN_H
#include "Mymain.h"

class Myfdcan {
private:
    FDCAN_HandleTypeDef *hfdcan;
    FDCAN_FilterTypeDef FDCAN1_RXFilter;
public:
    Myfdcan(FDCAN_HandleTypeDef *hfdcan);
    int CanFilter_Normal_Init(uint32_t ID1, uint32_t ID2);
    int Can_Start( );
    int Can_SendMessage(uint8_t *message,uint32_t lenth, uint32_t ID);
    int Can_ScanMessage(uint8_t *buffer);
};


#endif //BLINKE_MYFDCAN_H
