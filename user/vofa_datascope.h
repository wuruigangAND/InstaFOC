/*
 * vofa_datascope.h
 *
 *  Created on: 2024年7月10日
 *      Author: Railgun
 */

#ifndef USER_VOFA_DATASCOPE_H_
#define USER_VOFA_DATASCOPE_H_

//#include "sys_main.h"


#include "driverlib.h"
#include "device.h"

#define CHNNEL_NUM 5

typedef enum{
    data_ready  = 0,
    data_empty  = 1,
} data_scope_state_e;
/* 共用体定义 */
typedef union
{
    float32_t DataFloat;
    uint16_t DataUint16[2];
}BSP_FLOAT_UNION;

typedef struct _Scope_Params_{

    volatile float32_t *ptrData[CHNNEL_NUM];

    float32_t  gain[CHNNEL_NUM];

    int16_t    offset[CHNNEL_NUM];

    data_scope_state_e data_state;//状态

    BSP_FLOAT_UNION DataSend[CHNNEL_NUM];

    void (*SendData)(BSP_FLOAT_UNION* data,uint16_t len);
    void (*ScopeDataDealAndSend)(void);

}Scope_Params;


extern Scope_Params data_scope;


void Data_Scope_Init(void);
void ScopeDataSend(void);



#endif /* USER_VOFA_DATASCOPE_H_ */
