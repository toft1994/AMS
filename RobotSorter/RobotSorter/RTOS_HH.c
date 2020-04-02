///******************************************************
//FreeRTOS demo program.
//Implementing 2 tasks, each blinking a LED.
//
//Target = "Arduino Mega2560" + "PR I/O Shield"
//
//Henning Hargaard 25.2.2018
//*******************************************************/
//#include <avr/io.h>
//#include "Source/include/FreeRTOS.h"
//#include "Source/include/task.h"
//#include "led.h"
//#include "switch.h"
//#include "uart.h"
//
//#include "Source/include/semphr.h"
//#include "Source/include/queue.h"
//#include "Source/include/portmacro.h"
//
//xQueueHandle queueHandle = NULL;
//xSemaphoreHandle binarySemaphone = NULL;
//unsigned char count = 0U;
//const uint16_t xDelay = 50 / portTICK_RATE_MS;
//
//void FirstTask( void *pvParameters )
//{
	//while(1)
	//{
		//while ( switchOn(0U) )
		//if ( xSemaphoreTake(binarySemaphone, 10) == pdTRUE )
		//{
			//count++;
			//xQueueSend( queueHandle, ( void * ) &count, 10 );
			//xSemaphoreGive(binarySemaphone);
			//vTaskDelay( xDelay );
		//}
	//}
//}
//
//void SecondTask( void *pvParameters )
//{
	//while(1)
	//{
		//while ( switchOn(1U) )
		//if ( xSemaphoreTake(binarySemaphone, 10) == pdTRUE )
		//{
			//count++;
			//xQueueSend( queueHandle, ( void * ) &count, 10 );
			//xSemaphoreGive(binarySemaphone);
			//vTaskDelay( xDelay );
		//}
	//}
//}
//
//void ThirdTask( void *pvParameters )
//{
	//while(1)
	//{
		//if( uxQueueMessagesWaiting( queueHandle ) > 0U )
		//{
			//unsigned char recivedItem = 0U;
			//xQueueReceive( queueHandle,	( void * ) &recivedItem, 10U );
			//writeAllLEDs( recivedItem );
			//taskENTER_CRITICAL();
			//SendInteger( recivedItem );
			//taskEXIT_CRITICAL();
		//}
	//}
//}
//
//void FourthTask( void *pvParameters )
//{
	//while(1)
	//{
		//while ( switchOn(2U) )
		//if ( xSemaphoreTake(binarySemaphone, 10) == pdTRUE )
		//{
			//count++;
			//xQueueSend( queueHandle, ( void * ) &count, 10 );
			//xSemaphoreGive(binarySemaphone);
			//vTaskDelay( xDelay );
		//}
	//}
//}
//
//int main(void)
//{
	//initLEDport();
	//initSwitchPort();
	//InitUART( 9600, 8, 'N' );
  //
	//queueHandle = xQueueCreate( 0xFF, sizeof( unsigned char ) );
	//vSemaphoreCreateBinary(binarySemaphone);
	//xSemaphoreGive(binarySemaphone);
  //
	//xTaskCreate( FirstTask, ( signed char * ) "First", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );
	//xTaskCreate( SecondTask, ( signed char * ) "Second", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );	
	//xTaskCreate( ThirdTask, ( signed char * ) "Third", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );
	//xTaskCreate( FourthTask, ( signed char * ) "Fourth", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );
  //
	//vTaskStartScheduler();
	//while(1)
	//{}
//}
//
