#ifndef _RTOS_TASK_H
#define _RTOS_TASK_H

#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "shell.h"
#include "math.h"

void two_led_toggle(void *p);
void function1(void);
void task_control(void);
void runonce_entry(void *p);
void print_string(void *p);
void task_create_entry(void *p);
void complex_algorithm();
void timed_task_entry(void *p);

#endif