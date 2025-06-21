#include "rtos_task.h"

//һ��������0
void runonce_entry(void *p)
{
	TaskHandle_t tmp_handle;
	
	vTaskDelay(8000);
	
	printf("system is booting!!\r\n");
	
	tmp_handle = xTaskGetHandle("runonce_entry_task");   //��ȡ��������main�еľ��
	
	vTaskDelete(tmp_handle);
}

//����1
void two_led_toggle(void *p)
{
 while(1)
 {
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_SET);
	vTaskDelay(1000);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
	vTaskDelay(1000);
 }
}

//����2
void function1(void)
{
 printf("ZNS is short for ZN'Shell!!\r\n");
}
ZNS_CMD_EXPORT(function1,This is a shell demo!)

//����3
//һ�������񣺹���ͻָ����κ�ɾ��
//count==3ɾ�����񣬲�����3ÿ��5s�����ָ�����
//ѭ�����κ�ɾ������
void task_control(void)
{
 TaskHandle_t tmp_handle;	
	
 int count = 0;
	
 tmp_handle = xTaskGetHandle("two_led_toggle_task");  //������������ȡ�����������ֱ���ֶ��Ҿ��
	
 while(1)
 {
	if(count == 3) 
	{
	 printf("task is deleted!\r\n");
	 vTaskDelete(tmp_handle);
	}
	else
	{
	 printf("task is suspended!\r\n");
	 vTaskSuspend(tmp_handle);
	 
   vTaskDelay(5000);
	 
	 printf("task is resumed!\r\n"); 
	 vTaskResume(tmp_handle);
	 
   vTaskDelay(5000);
		
	 count++;
	}
 }
}


//����0
void print_string(void *p)
{
 while(1)
 {
	printf("print_string_task is running...\r\n");
	vTaskDelay(1000);
 }
}



void complex_algorithm()
{
 float x = 0.0;
 int i = 0;

 for(i=0;i<10000;i++)
 {
	sinf(x);
	 
	x += 0.01;
 }
}

//��ʱ
void timed_task_entry(void *p)
{
 TickType_t xLastWakeTime;

 xLastWakeTime = xTaskGetTickCount();
	
 while(1)
 {
//	complex_algorithm();
//  HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_5);
	 
	vTaskDelayUntil(&xLastWakeTime,1000);
 }
}



void task_create_entry(void *p)
{	
 TaskHandle_t tmp_handle;	
 TaskHandle_t xHandle;
 TaskHandle_t xHandle2;
	
 vTaskDelay(8000);
	
 //=====================================
 printf("start to create tasks\r\n");	
	
 printf("create 1st task\r\n");
	
 xTaskCreate(timed_task_entry,"timed_task",128,(void *)0,10,&xHandle);
	
 //=====================================	

 tmp_handle = xTaskGetHandle("task_create_task");
	
 vTaskDelete(tmp_handle);
}





