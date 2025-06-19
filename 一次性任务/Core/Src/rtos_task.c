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



