/**
	\file STM32F0xx.c
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

//#define GLCD_DEVICE_STM32L0XX 0
#if defined(GLCD_DEVICE_STM32L0XX)

/* Includes from CMSIS and Peripheral Library */
#include "stm32l0xx.h"
#include "stm32l0xx_hal_gpio.h"
#include "stm32l0xx_hal_spi.h"
#include "stm32l0xx_hal_rcc.h"
//#include "stm32l0xx_misc.h"

/* Includes from GLCD */
#include "main.h"
#include "../glcd.h"
#include "inc/STM32L0xx.h"

void glcd_init(void)
{

	/* Declare GPIO and SPI init structures */
//	GPIO_InitTypeDef GPIO_InitStructure;
//	SPI_InitTypeDef  SPI_InitStructure;
	/* NVIC_InitTypeDef NVIC_InitStructure; */
	
	/* Initialise structures (which we will overide later) */
//	GPIO_StructInit(&GPIO_InitStructure);
//	SPI_StructInit(&SPI_InitStructure);
	
	/* Need to make start up the correct peripheral clocks */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

	/* SS pin */
//	GPIO_InitStructure.Pin   = CONTROLLER_SPI_SS_PIN;
//	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
//	GPIO_InitStructure.Mode  = GPIO_MODE_OUTPUT_PP;
//	GPIO_Init(CONTROLLER_SPI_SS_PORT, &GPIO_InitStructure);
	
	/* DC pin */
//	GPIO_InitStructure.Pin = CONTROLLER_SPI_DC_PIN;
//	GPIO_Init(CONTROLLER_SPI_DC_PORT, &GPIO_InitStructure);

	/* RESET pin */
//	GPIO_InitStructure.Pin = CONTROLLER_SPI_RST_PIN;
//	GPIO_Init(CONTROLLER_SPI_RST_PORT, &GPIO_InitStructure);

	/* Make sure chip is de-selected by default */

	GLCD_A0_LOW();
	GLCD_SELECT();
	GLCD_RESET_LOW();
	HAL_Delay(1);
	GLCD_RESET_HIGH();
	HAL_Delay(5);

	/* Set up GPIO for SPI pins */
//	GPIO_InitStructure.Pin   = CONTROLLER_SPI_SCK_PIN | CONTROLLER_SPI_MISO_PIN | CONTROLLER_SPI_MOSI_PIN;
//	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
//	GPIO_InitStructure.Mode  = GPIO_MODE_AF_PP;
//	GPIO_Init(CONTROLLER_SPI_PORT, &GPIO_InitStructure);

	/* Configure alternate function mode for SPI pins */
//	GPIO_PinAFConfig(GPIOA,CONTROLLER_SPI_SCK_PINSRC,GPIO_AF_0);
//	GPIO_PinAFConfig(GPIOA,CONTROLLER_SPI_MOSI_PINSRC,GPIO_AF_0);
//	GPIO_PinAFConfig(GPIOA,CONTROLLER_SPI_MISO_PINSRC,GPIO_AF_0);

	/* Initialise SPI */
	//Deja fait dans le main
//	SPI_InitStructure.Direction         = SPI_Direction_2Lines_FullDuplex;
//	SPI_InitStructure.Mode              = SPI_Mode_Master;
//	SPI_InitStructure.DataSize          = SPI_DataSize_8b;
//	SPI_InitStructure.CPOL              = SPI_CPOL_Low;
//	SPI_InitStructure.CPHA              = SPI_CPHA_2Edge;
//	SPI_InitStructure.NSS               = SPI_NSS_Soft;
//	SPI_InitStructure.BaudRatePrescaler = SPI_BaudRatePrescaler_32; /* Set clock speed! */
//	SPI_InitStructure.FirstBit          = SPI_FirstBit_MSB;
//	SPI_InitStructure.CRCPolynomial     = 7;
//	SPI_Init(CONTROLLER_SPI_NUMBER, &SPI_InitStructure);

	/* Enable SPI interupts */
	/*
	SPI_I2S_ITConfig(CONTROLLER_SPI_NUMBER, SPI_I2S_IT_TXE, ENABLE);
	NVIC_InitStructure.NVIC_IRQChannel = SPI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
	NVIC_Init(&NVIC_InitStructure);
	*/
	
	/* Enable SPI */
	//SPI_Cmd(CONTROLLER_SPI_NUMBER, ENABLE);


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
