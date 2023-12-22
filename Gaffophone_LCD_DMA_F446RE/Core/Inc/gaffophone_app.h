/*
 * gaffophone.h
 *
 *  Created on: DEc 21, 2023
 *      Author: denis
 */

#ifndef INC_GAFFOPHONE_APP_H_
#define INC_GAFFOPHONE_APP_H_

#include "main.h"
#include "../librairie/glcd/glcd.h"


extern uint8_t flag_bp_down;
typedef enum {
	lcd_init,
	standby,
	_playnote,
	playnote,
	_stop,
	stop
} fsm_states;

//Machine d'état du systeme
void gaffophone_app_fsm(void);


#endif /* INC_GAFFOPHONE_APP_H_ */
