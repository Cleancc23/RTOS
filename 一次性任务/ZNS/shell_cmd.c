#include "shell_cmd.h"


//print task information
void pti(void)
{
 TaskHandle_t tmp_handle;
 TaskStatus_t xTaskDetails;
	
 tmp_handle = xTaskGetHandle("two_led_toggle_task"); 
	
 vTaskGetInfo(tmp_handle,&xTaskDetails,1,eInvalid);
	
 taskENTER_CRITICAL(); 
	 
 printf("TaskName : %s , TaskNumber = %d , CurrentState = %d , CurrentPriority = %d , BasePriority =  %d , RunTimeCounter = %d ,StackHighWaterMark = %d , TickCount = %d\r\n\r\n",
	       xTaskDetails.pcTaskName,xTaskDetails.xTaskNumber,xTaskDetails.eCurrentState,xTaskDetails.uxCurrentPriority,xTaskDetails.uxBasePriority,xTaskDetails.ulRunTimeCounter,xTaskDetails.usStackHighWaterMark,xTaskGetTickCount());
 
 taskEXIT_CRITICAL();  
}
ZNS_CMD_EXPORT(pti,show task two_led_toggle info)

//print task list任务列表
void ptl(void)
{
 char str[200];
	
 vTaskList(str);
	 
 taskENTER_CRITICAL();  
	 
 printf("TaskName              State Priority  Stack  Number \r\n%s\r\n",str);
	 
 taskEXIT_CRITICAL(); 
}
ZNS_CMD_EXPORT(ptl, show tasklist)

//print task  memory
void mem(void)
{
 taskENTER_CRITICAL(); 
	
 printf("FreeHeapSize = %d   EverFreeHeapSize = %d\r\n",xPortGetFreeHeapSize(),xPortGetMinimumEverFreeHeapSize());
	
 taskEXIT_CRITICAL();
}
ZNS_CMD_EXPORT(mem, show heap size)