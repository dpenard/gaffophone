/**
	\file STM32F4xx.c
	\author Andy Gock
	\brief Functions specific to STM32 F0 ARM Cortex-M0 devices.
 */

/*
	Copyright (c) 2012, Andy Gock

	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
		* Redistributions of source code must retain the above copyright
		  notice, this list of conditions and the following disclaimer.
		* Redistributions in binary form must reproduce the above copyright
		  notice, this list of conditions and the following disclaimer in the
		  documentation and/or other materials provided with the distribution.
		* Neither the name of Andy Gock nor the
		  names of its contributors may be used to endorse or promote products
		  derived from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL ANDY GOCK BE LIABLE FOR ANY
	DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define GLCD_DEVICE_STM32F4XX 1
#if defined(GLCD_DEVICE_STM32F4XX)

/* Includes from CMSIS and Peripheral Library */
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_rcc.h"

/* Includes from GLCD */
#include "main.h"
#include "../glcd.h"
#include "inc/STM32F4xx.h"
extern SPI_HandleTypeDef hspi1;

void glcd_init(void)
{
	/* Make sure chip is de-selected by default */

	GLCD_A0_LOW();
	GLCD_SELECT();
	GLCD_RESET_LOW();
	HAL_Delay(1);
	GLCD_RESET_HIGH();
	HAL_Delay(5);



#if defined(GLCD_CONTROLLER_PCD8544)
	glcd_PCD8544_init();

#elif defined(GLCD_CONTROLLER_ST7565R)
	glcd_ST7565R_init();

	/* Set all dots black and hold for 0.5s, then clear it, we do this so we can visually check init sequence is working */
	glcd_all_on();
	HAL_Delay(500);
	glcd_normal();

	glcd_set_start_line(0);
	glcd_clear_now();

#else
	#error "Controller not supported by STM32F10x"

#endif

	glcd_select_screen(glcd_buffer,&glcd_bbox);
	glcd_clear();



}

void glcd_spi_write(uint8_t c)
{

	GLCD_SELECT();
	HAL_SPI_Transmit(&hspi1, &c, sizeof(c), 1);
	/* Wait until entire byte has been read (which we discard anyway) */
	//while(SPI_I2S_GetFlagStatus(CONTROLLER_SPI_NUMBER, SPI_I2S_FLAG_BSY) != RESET);
	//while(HAL_SPI_STATE_BUSY == HAL_SPI_GetState(&hspi1));
	GLCD_DESELECT();
}

void glcd_reset(void)
{
	/* Toggle RST low to reset. Minimum pulse 100ns on datasheet. */
	GLCD_SELECT();
	GLCD_RESET_LOW();
	HAL_Delay(GLCD_RESET_TIME);
	GLCD_RESET_HIGH();
	GLCD_DESELECT();
}

#endif
