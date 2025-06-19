#include "task_init.h"

extern void print1(void *p);
extern void print2(void *p);

/* ��������ĺ��� */
void task_init( void )
{
 BaseType_t xReturned;
 TaskHandle_t xHandle = NULL;

 /* �������񣬴洢��� */
 xReturned = xTaskCreate(
                    print1,       /* ִ������ĺ��� */
                    "print1Task",          /* �������� */
                    STACK_SIZE,      /* ��ջ��С����λΪ�� */
                    ( void * ) 1,    /* ���ݸ�����Ĳ��� */
                    tskIDLE_PRIORITY,/* ������������ȼ� */
                    &xHandle );      /* ���ڴ��ݴ����������� */
										
 xReturned = xTaskCreate(
                    print2,       /* ִ������ĺ��� */
                    "print2Task",          /* �������� */
                    STACK_SIZE,      /* ��ջ��С����λΪ�� */
                    ( void * ) 1,    /* ���ݸ�����Ĳ��� */
                    tskIDLE_PRIORITY,/* ������������ȼ� */
                    &xHandle );      /* ���ڴ��ݴ����������� */
 
 vTaskStartScheduler();										 
}
