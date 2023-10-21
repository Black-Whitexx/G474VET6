//
// Created by YINING on 2023/10/21.
//

#include "Myfdcan.h"

Myfdcan::Myfdcan(FDCAN_HandleTypeDef *hfdcan_) {
    hfdcan = hfdcan_;
}

int Myfdcan::CanFilter_Normal_Init(uint32_t ID1, uint32_t ID2) {
    //只改变ID的过滤器初始化
    FDCAN1_RXFilter.IdType=FDCAN_STANDARD_ID;
    FDCAN1_RXFilter.FilterIndex=0;
    FDCAN1_RXFilter.FilterType=FDCAN_FILTER_MASK;
    FDCAN1_RXFilter.FilterConfig=FDCAN_FILTER_TO_RXFIFO0;
    FDCAN1_RXFilter.FilterID1=ID1;
    FDCAN1_RXFilter.FilterID2=ID2;
    if(HAL_FDCAN_ConfigFilter(hfdcan,&FDCAN1_RXFilter)==HAL_OK) //婊ゆ尝鍣ㄥ垵濮嬪寲
    {
        return 0;
    }
    else{
        return 1;
    }
}

int Myfdcan::Can_Start( ) {
    //开启CAN
    HAL_FDCAN_Start(hfdcan);
    HAL_FDCAN_ActivateNotification(hfdcan,FDCAN_IT_RX_FIFO0_NEW_MESSAGE,0);//开启接收通知
    return 0;
}

int Myfdcan::Can_SendMessage(uint8_t *message, uint32_t lenth, uint32_t ID) {
    FDCAN_TxHeaderTypeDef fdcan_TxHeader;
    fdcan_TxHeader.Identifier=ID;                           //32位ID
    fdcan_TxHeader.IdType=FDCAN_STANDARD_ID;                  //标准ID
    fdcan_TxHeader.TxFrameType=FDCAN_DATA_FRAME;              //数据帧
    fdcan_TxHeader.DataLength= lenth;                            //数据长度
    fdcan_TxHeader.ErrorStateIndicator=FDCAN_ESI_ACTIVE;
    fdcan_TxHeader.BitRateSwitch=FDCAN_BRS_OFF;               //关闭速率切换
    fdcan_TxHeader.FDFormat=FDCAN_CLASSIC_CAN;                //传统的CAN模式
    fdcan_TxHeader.TxEventFifoControl=FDCAN_NO_TX_EVENTS;     //无发送事件
    fdcan_TxHeader.MessageMarker=0;
    if(HAL_FDCAN_AddMessageToTxFifoQ(hfdcan,&fdcan_TxHeader,message)==HAL_OK) return 0;//发送
    else return 1;
}

int Myfdcan::Can_ScanMessage(uint8_t *buffer) {
    FDCAN_RxHeaderTypeDef RXHeader;
    if(HAL_FDCAN_GetRxMessage(hfdcan,FDCAN_RX_FIFO0,&RXHeader,buffer)==HAL_OK)return 0;//接收数据
    else return 1;
}