#include "task_init.h"

extern void print1(void *p);
extern void print2(void *p);

/* 创建任务的函数 */
void task_init( void )
{
 BaseType_t xReturned;
 TaskHandle_t xHandle = NULL;

 /* 创建任务，存储句柄 */
 xReturned = xTaskCreate(
                    print1,       /* 执行任务的函数 */
                    "print1Task",          /* 任务名称 */
                    STACK_SIZE,      /* 堆栈大小，单位为字 */
                    ( void * ) 1,    /* 传递给任务的参数 */
                    tskIDLE_PRIORITY,/* 创建任务的优先级 */
                    &xHandle );      /* 用于传递创建的任务句柄 */
										
 xReturned = xTaskCreate(
                    print2,       /* 执行任务的函数 */
                    "print2Task",          /* 任务名称 */
                    STACK_SIZE,      /* 堆栈大小，单位为字 */
                    ( void * ) 1,    /* 传递给任务的参数 */
                    tskIDLE_PRIORITY,/* 创建任务的优先级 */
                    &xHandle );      /* 用于传递创建的任务句柄 */
 
 vTaskStartScheduler();										 
}
