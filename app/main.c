
#include "MKL25Z4.h"
#include "system_MKL25Z4.h"
#include "FreeRTOS.h"
#include "task.h"

void 
prvSetupHardware( void )
{
	SystemInit();
	SystemCoreClockUpdate();
}

void 
taskA( void *pvParameters)
{
	for(;;)
	{

	}
}

int 
main(void)
{
	prvSetupHardware();

	xTaskCreate( taskA, 
				 "taskA", 
				 configMINIMAL_STACK_SIZE, 
				 ( void * ) NULL, 
				 3,
				 NULL 
				);

	vTaskStartScheduler();
	return 0;
}


void 
vConfigureTimerForRunTimeStats( void )
{

}

void 
vApplicationTickHook( void )
{

}

void 
vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{

}