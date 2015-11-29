/**
  ******************************************************************************
  * @file    main.c
  * @author  Michael Weinberger
  * @version 1.0
  * @date    14.11.2015
  * @brief   Hauptklasse, Ausfuehren der State Machine
  ******************************************************************************
*/

#include "control.h"
#include "ampel.h"
#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

			
ampelparameter data;

int main(void)
{

	SystemInit();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);

	led_init();

	ampelparameter* run = &data;
	for (;;) {
		ampelsteuerung(run);
	}

	return EXIT_SUCCESS;

}
