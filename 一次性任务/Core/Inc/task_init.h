#ifndef __UART_H
#define __UART_H

#include "FreeRTOS.h"
#include "task.h"
#include "stm32f1xx_hal.h"
#include "stdio.h"

#define STACK_SIZE  configMINIMAL_STACK_SIZE

extern void task_init(void);

#endif
