#ifndef _RTOS_TASK_H
#define _RTOS_TASK_H

#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "shell.h"

void two_led_toggle(void *p);
void function1(void);
void task_control(void);
void task_create_entry(void *p);
void print_string(void *p);

#endif