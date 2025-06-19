#include "rtos_task.h"

//一次性任务0
void runonce_entry(void *p)
{
	TaskHandle_t tmp_handle;
	
	vTaskDelay(8000);
	
	printf("system is booting!!\r\n");
	
	tmp_handle = xTaskGetHandle("runonce_entry_task");   //获取该任务在main中的句柄
	
	vTaskDelete(tmp_handle);
}

//任务1
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

//任务2
void function1(void)
{
 printf("ZNS is short for ZN'Shell!!\r\n");
}
ZNS_CMD_EXPORT(function1,This is a shell demo!)

//任务3
//一次性任务：挂起和恢复三次后删除
//count==3删除任务，不等于3每隔5s挂起或恢复任务。
//循环三次后，删掉任务
void task_control(void)
{
 TaskHandle_t tmp_handle;	
	
 int count = 0;
	
 tmp_handle = xTaskGetHandle("two_led_toggle_task");  //根据任务名获取句柄，而不是直接手动找句柄
	
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



