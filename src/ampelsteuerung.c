/**
  ******************************************************************************
  * @file    ampelsteuerung.c
  * @author  Michael Weinberger
  * @version 1.0
  * @date    14.11.2015
  * @brief   Implementierung einer Event Centric State Machine zur Steuerung einer Ampel
  ******************************************************************************
*/

#include "control.h"
#include "ampel.h"

/**
 * @brief Implementierung einer Event Centric State Machine zur Steuerung einer Ampel
 *
 * @param none
 * @retval none
 */
void ampelsteuerung(ampelparameter* repr) {

	switch (repr->event) {

		case HALT:

			if (repr->zustand == ROT) {

				led_rot();

				repr->zustand = ROT_GELB;
				repr->event = VORBEREITUNG_FAHREN;

			} else {

				led_off();

				repr->event = FALSE;

			}

			break;

		case VORBEREITUNG_FAHREN:

			if (repr->zustand == ROT_GELB) {

				led_uebergang();

				repr->zustand = GRUEN;
				repr->event = FAHREN;

			} else {

				led_off();

				repr->event = FALSE;

			}

			break;

		case FAHREN:

			if (repr->zustand == GRUEN) {

				led_gruen();

				repr->zustand = GRUEN_BLINKEN;
				repr->event = VORBEREITUNG_HALT;

			} else {

				led_off();

				repr->event = FALSE;

			}

			break;

		case VORBEREITUNG_HALT:

			if (repr->zustand == GRUEN_BLINKEN) {

				led_gruen_blinken();

				repr->event = ACHTUNG;
				repr->zustand = GELB;

			} else {

				led_off();

				repr->event = FALSE;

			}

			break;

		case ACHTUNG:

			if (repr->zustand == GELB) {

				led_gelb();

				repr->event = HALT;
				repr->zustand = ROT;

			} else {

				led_off();

				repr->event = FALSE;

			}

			break;

		default:

			repr->event = HALT;
			repr->zustand = ROT;

			break;
	}
}

