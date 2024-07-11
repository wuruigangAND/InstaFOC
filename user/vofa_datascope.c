/*
 * vofa_datascope.c
 *
 *  Created on: 2024年7月10日
 *      Author: Railgun
 */
#include "vofa_datascope.h"

const char tail[4] = {0x00,0x00,0x80,0x7f};

Scope_Params data_scope;



/* 浮点数发送函数 len:BSP_FLOAT_UNION数量*/
void BspSendFloatFifo(BSP_FLOAT_UNION* data,uint16_t len)
{
    uint16_t j;
    uint32_t base = SCIA_BASE;

    for(j = 0; j < len ; j ++){

        if(SCI_isFIFOEnabled(base))
           {
                while(SCI_getTxFIFOStatus(base) == SCI_FIFO_TX15);
                HWREGH(base + SCI_O_TXBUF) = data[j].DataUint16[0]&0xff;
                while(SCI_getTxFIFOStatus(base) == SCI_FIFO_TX15);
                HWREGH(base + SCI_O_TXBUF) = data[j].DataUint16[0]>>8;
                while(SCI_getTxFIFOStatus(base) == SCI_FIFO_TX15);
                HWREGH(base + SCI_O_TXBUF) = data[j].DataUint16[1]&0xff;
                while(SCI_getTxFIFOStatus(base) == SCI_FIFO_TX15);
                HWREGH(base + SCI_O_TXBUF) = data[j].DataUint16[1]>>8;
               }
           else
           {
               //
               // FIFO is not enabled.
               // For loop to write (Blocking) 'length' number of characters
               //
                while(SCI_getTxFIFOStatus(base) == SCI_FIFO_TX15);
                HWREGH(base + SCI_O_TXBUF) = data[j].DataUint16[0]&0xff;
                while(SCI_getTxFIFOStatus(base) == SCI_FIFO_TX15);
                HWREGH(base + SCI_O_TXBUF) = data[j].DataUint16[0]>>8;
                while(SCI_getTxFIFOStatus(base) == SCI_FIFO_TX15);
                HWREGH(base + SCI_O_TXBUF) = data[j].DataUint16[1]&0xff;
                while(SCI_getTxFIFOStatus(base) == SCI_FIFO_TX15);
                HWREGH(base + SCI_O_TXBUF) = data[j].DataUint16[1]>>8;
           }
    }
    SCI_writeCharArray(SCIA_BASE, (uint16_t*)tail, 4);
}

void ScopeDataDealAndSend(void){
    uint16_t i ;
    for(i = 0; i < CHNNEL_NUM; i ++){
        data_scope.DataSend[i].DataFloat =
                (*(data_scope.ptrData[i]))* data_scope.gain[i] + data_scope.offset[i];
    }
    data_scope.SendData(data_scope.DataSend,CHNNEL_NUM);
}

void Data_Scope_Init(void){
    data_scope.data_state = data_empty;
    data_scope.SendData = BspSendFloatFifo;
    data_scope.ScopeDataDealAndSend = ScopeDataDealAndSend;
    uint16_t i ;
        for(i = 0; i < CHNNEL_NUM; i ++){
            data_scope.gain[i] = 1;
            data_scope.offset[i] = 0;
        }

}
