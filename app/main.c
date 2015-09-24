
#include "MKL25Z4.h"
#include "system_MKL25Z4.h"
#include "FreeRTOS.h"
#include "task.h"

void prvSetupHardware( void )
{
	SystemInit();
	
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

    PORTB->PCR[18] = PORT_PCR_MUX(1);
    PTB->PDDR |= (1 << 18);
    PTB->PSOR |= (1 << 18);

    PORTB->PCR[19] = PORT_PCR_MUX(1);
    PTB->PDDR |= (1 << 19);
    PTB->PSOR |= (1 << 19);

    PORTD->PCR[1] = PORT_PCR_MUX(1);
    PTD->PDDR |= (1 << 1);
    PTD->PSOR |= (1 << 1);
}

void taskA( void *pvParameters)
{
	for(;;)
	{
		PTB->PTOR |= (1 << 18);
		vTaskDelay(300);
	}
}

void taskB( void *pvParameters)
{
	for(;;)
	{
		PTB->PTOR |= (1 << 19);
		vTaskDelay(200);
	}
}

void taskC( void *pvParameters)
{
	for(;;)
	{
		PTD->PTOR |= (1 << 1);
		vTaskDelay(400);
	}
}

void taskD( void *pvParameters)
{
	for(;;)
	{
		vTaskDelay(200);
	}
}

int main(void)
{
	prvSetupHardware();
	xTaskCreate( taskA, 
				 "taskA", 
				 configMINIMAL_STACK_SIZE, 
				 ( void * ) NULL, 
				 3,
				 NULL 
				);

	xTaskCreate( taskB, 
				 "taskB", 
				 configMINIMAL_STACK_SIZE, 
				 ( void * ) NULL, 
				 4,
				 NULL 
				);

	xTaskCreate( taskC, 
				 "taskC", 
				 configMINIMAL_STACK_SIZE, 
				 ( void * ) NULL, 
				 5,
				 NULL 
				);

	xTaskCreate( taskD, 
				 "taskD", 
				 configMINIMAL_STACK_SIZE, 
				 ( void * ) NULL, 
				 6,
				 NULL 
				);


	vTaskStartScheduler();
	for(;;);
	return 0;
}


void vConfigureTimerForRunTimeStats( void )
{

}

void vApplicationTickHook( void )
{

}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{

}