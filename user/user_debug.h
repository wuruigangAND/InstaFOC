/*
 * user_debug.h
 *
 *  Created on: 2024Äê7ÔÂ8ÈÕ
 *      Author: Railgun
 */

#ifndef USER_DEBUG_H_
#define USER_DEBUG_H_

//#include "sys_main.h"
#include "driverlib.h"
#include "device.h"

void dclink_debug_init(void);
void uart_init(uint32_t baud);
void user_io(void);

#endif /* USER_DEBUG_H_ */
