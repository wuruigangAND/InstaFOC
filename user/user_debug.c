/*
 * user.c
 *
 *  Created on: 2024年7月8日
 *      Author: Railgun
 */

#include "user_debug.h"
#include "user_mtr1.h"


//配置几个同步的PWM用于观察触发点
void dclink_debug_init(void){
    uint16_t       pwmPeriodCycles = (uint16_t)(USER_M1_PWM_TBPRD_NUM);
    GPIO_setDirectionMode(12, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(12, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_12_EPWM7_A);
    GPIO_setDirectionMode(6, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(6, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_6_EPWM4_A);

    //设置EPWM7
   EPWM_setTimeBaseCounterMode(EPWM7_BASE,
                               EPWM_COUNTER_MODE_UP_DOWN);

   EPWM_disablePhaseShiftLoad(EPWM7_BASE);

   EPWM_setPeriodLoadMode(EPWM7_BASE, EPWM_PERIOD_DIRECT_LOAD);

   EPWM_enableSyncOutPulseSource(EPWM7_BASE,
                                 EPWM_SYNC_OUT_PULSE_ON_SOFTWARE);

   EPWM_setClockPrescaler(EPWM7_BASE, EPWM_CLOCK_DIVIDER_1,
                            EPWM_HSCLOCK_DIVIDER_1);

   EPWM_setCountModeAfterSync(EPWM7_BASE,
                              EPWM_COUNT_MODE_UP_AFTER_SYNC);

   EPWM_setEmulationMode(EPWM7_BASE, EPWM_EMULATION_FREE_RUN);

   // setup the Timer-Based Phase Register (TBPHS)
   EPWM_setPhaseShift(EPWM7_BASE, 0);

   // setup the Time-Base Counter Register (TBCTR)
   EPWM_setTimeBaseCounter(EPWM7_BASE, 0);

   // setup the Time-Base Period Register (TBPRD)
   // set to zero initially
   EPWM_setTimeBasePeriod(EPWM7_BASE, 0);

   // setup the Counter-Compare Control Register (CMPCTL)
   EPWM_setCounterCompareShadowLoadMode(EPWM7_BASE,
                                        EPWM_COUNTER_COMPARE_A,
                                        EPWM_COMP_LOAD_ON_CNTR_ZERO);

   EPWM_setCounterCompareShadowLoadMode(EPWM7_BASE,
                                        EPWM_COUNTER_COMPARE_B,
                                        EPWM_COMP_LOAD_ON_CNTR_ZERO);

   EPWM_setCounterCompareShadowLoadMode(EPWM7_BASE,
                                        EPWM_COUNTER_COMPARE_C,
                                        EPWM_COMP_LOAD_ON_CNTR_ZERO);

   EPWM_setCounterCompareShadowLoadMode(EPWM7_BASE,
                                        EPWM_COUNTER_COMPARE_D,
                                        EPWM_COMP_LOAD_ON_CNTR_ZERO);
   EPWM_disableChopper(EPWM7_BASE);
   EPWM_setActionQualifierAction(EPWM7_BASE,
                                         EPWM_AQ_OUTPUT_A,
                                         EPWM_AQ_OUTPUT_HIGH,
                                         EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

   EPWM_setActionQualifierAction(EPWM7_BASE,
                                 EPWM_AQ_OUTPUT_A,
                                 EPWM_AQ_OUTPUT_HIGH,
                                 EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);

   EPWM_setActionQualifierAction(EPWM7_BASE,
                                 EPWM_AQ_OUTPUT_A,
                                 EPWM_AQ_OUTPUT_LOW,
                                 EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

   EPWM_setActionQualifierAction(EPWM7_BASE,
                                 EPWM_AQ_OUTPUT_A,
                                 EPWM_AQ_OUTPUT_LOW,
                                 EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);





//设置EPWM4
    EPWM_setTimeBaseCounterMode(EPWM4_BASE,EPWM_COUNTER_MODE_UP_DOWN);

   EPWM_disablePhaseShiftLoad(EPWM4_BASE);

   EPWM_setPeriodLoadMode(EPWM4_BASE, EPWM_PERIOD_DIRECT_LOAD);

   EPWM_enableSyncOutPulseSource(EPWM4_BASE,
                                 EPWM_SYNC_OUT_PULSE_ON_SOFTWARE);

   EPWM_setClockPrescaler(EPWM4_BASE, EPWM_CLOCK_DIVIDER_1,
                            EPWM_HSCLOCK_DIVIDER_1);

   EPWM_setCountModeAfterSync(EPWM4_BASE,
                              EPWM_COUNT_MODE_UP_AFTER_SYNC);

   EPWM_setEmulationMode(EPWM4_BASE, EPWM_EMULATION_FREE_RUN);

   // setup the Timer-Based Phase Register (TBPHS)
   EPWM_setPhaseShift(EPWM4_BASE, 0);

   // setup the Time-Base Counter Register (TBCTR)
   EPWM_setTimeBaseCounter(EPWM4_BASE, 0);

   // setup the Time-Base Period Register (TBPRD)
   // set to zero initially
   EPWM_setTimeBasePeriod(EPWM4_BASE, 0);

   // setup the Counter-Compare Control Register (CMPCTL)
   EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE,
                                        EPWM_COUNTER_COMPARE_A,
                                        EPWM_COMP_LOAD_ON_CNTR_ZERO);

   EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE,
                                        EPWM_COUNTER_COMPARE_B,
                                        EPWM_COMP_LOAD_ON_CNTR_ZERO);

   EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE,
                                        EPWM_COUNTER_COMPARE_C,
                                        EPWM_COMP_LOAD_ON_CNTR_ZERO);

   EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE,
                                        EPWM_COUNTER_COMPARE_D,
                                        EPWM_COMP_LOAD_ON_CNTR_ZERO);
   EPWM_disableChopper(EPWM4_BASE);
   EPWM_setActionQualifierAction(EPWM4_BASE,
                                            EPWM_AQ_OUTPUT_A,
                                            EPWM_AQ_OUTPUT_HIGH,
                                            EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

  EPWM_setActionQualifierAction(EPWM4_BASE,
                                EPWM_AQ_OUTPUT_A,
                                EPWM_AQ_OUTPUT_HIGH,
                                EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);

  EPWM_setActionQualifierAction(EPWM4_BASE,
                                EPWM_AQ_OUTPUT_A,
                                EPWM_AQ_OUTPUT_LOW,
                                EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

  EPWM_setActionQualifierAction(EPWM4_BASE,
                                EPWM_AQ_OUTPUT_A,
                                EPWM_AQ_OUTPUT_LOW,
                                EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);


   EPWM_setTimeBasePeriod(EPWM4_BASE, pwmPeriodCycles);//pwmPeriodCycles = 100*1000/15/2 = 3333.33
   EPWM_setTimeBasePeriod(EPWM7_BASE, pwmPeriodCycles);

   EPWM_setCounterCompareValue(EPWM4_BASE,
                                   EPWM_COUNTER_COMPARE_A, pwmPeriodCycles>>1);
   EPWM_setCounterCompareValue(EPWM7_BASE,
                                      EPWM_COUNTER_COMPARE_A, pwmPeriodCycles>>1);

}


void uart_init(uint32_t baud){
    unsigned char *msg;
    //
    // GPIO28 is the SCI Rx pin.
    //
    GPIO_setPinConfig(DEVICE_GPIO_CFG_SCIRXDA);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_SCIRXDA, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_SCIRXDA, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SCIRXDA, GPIO_QUAL_ASYNC);

    //
    // GPIO29 is the SCI Tx pin.
    //
    GPIO_setPinConfig(DEVICE_GPIO_CFG_SCITXDA);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_SCITXDA, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_SCITXDA, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SCITXDA, GPIO_QUAL_ASYNC);

    SCI_performSoftwareReset(SCIA_BASE);
    SCI_setConfig(SCIA_BASE, DEVICE_LSPCLK_FREQ, baud, (SCI_CONFIG_WLEN_8 |
                                                            SCI_CONFIG_STOP_ONE |
                                                            SCI_CONFIG_PAR_NONE));
    SCI_resetChannels(SCIA_BASE);
    SCI_resetRxFIFO(SCIA_BASE);
    SCI_resetTxFIFO(SCIA_BASE);
    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_TXFF | SCI_INT_RXFF);
    SCI_enableFIFO(SCIA_BASE);
    SCI_enableModule(SCIA_BASE);
    SCI_performSoftwareReset(SCIA_BASE);

    msg = "\r\n\n\nHello World!\0";
    SCI_writeCharArray(SCIA_BASE, (uint16_t*)msg, 17);
//    msg = "uart init sccuess!\r\n\0";
//    SCI_writeCharArray(SCIA_BASE, (uint16_t*)msg, sizeof(msg));

}

void user_io(void){
    GPIO_setDirectionMode(37, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(37, GPIO_PIN_TYPE_PULLUP);
    GPIO_setPinConfig(GPIO_37_GPIO37);
    GPIO_setDirectionMode(44, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(44, GPIO_PIN_TYPE_PULLUP);
    GPIO_setPinConfig(GPIO_44_GPIO44);
}
