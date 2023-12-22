/*
 * gaffophone_app.c
 *
 *  Created on: Dec 21, 2023
 *      Author: denis
 */

#include "gaffophone_app.h"
#include "../librairie/glcd/fonts/font5x7.h"
#include "../librairie/glcd/glcd.h"

void gaffophone_app_fsm(void) {
	fsm_states etat_actuel;
	static fsm_states etat_futur = lcd_init;
	etat_actuel = etat_futur;

	//je réfléchis
	switch(etat_actuel){
	  case lcd_init:
		  etat_futur = standby;
		  break;

	  case standby:
		  if (flag_bp_down == 1) {
			  etat_futur = _playnote;
		  }
		  break;

	  case _playnote:
		  if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin)) {
			  etat_futur = playnote;
			  flag_bp_down = 0;
		  }
		  break;

	  case playnote:
		  if (flag_bp_down == 1) {
			  etat_futur = _stop;
		  }
	  break;

	  case _stop:
		  if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin)) {
			  etat_futur = stop;
			  flag_bp_down = 0;
		  }
	  break;

	  case stop:
		  if (flag_bp_down == 1) {
			  etat_futur = _playnote;
		  }
	  break;
	}
	//j'agis
	switch(etat_actuel){
	  case lcd_init:
		  glcd_init();
		  glcd_clear();

	  break;
	  case standby:
			glcd_tiny_set_font(Font5x7,5,7,32,127);
			glcd_clear_buffer();
			glcd_tiny_draw_string(0,0,"Generateur I2S");
			glcd_write();
		  break;

	  case _playnote:
			glcd_tiny_set_font(Font5x7,5,7,32,127);
			glcd_clear_buffer();
			glcd_tiny_draw_string(0,0,"play");
			glcd_write();
	  break;
	  case playnote:
	  break;
	  case _stop:
			glcd_tiny_set_font(Font5x7,5,7,32,127);
			glcd_clear_buffer();
			glcd_tiny_draw_string(0,0,"stop");
			glcd_write();
	  break;
	  case stop:
	  break;
	}
}

