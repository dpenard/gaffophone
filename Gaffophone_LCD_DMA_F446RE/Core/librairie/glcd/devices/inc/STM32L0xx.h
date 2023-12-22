/**
	\file STM32F0xx.h
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

#ifndef STM32L0XX_H_
#define STM32L0XX_H_

#if defined(GLCD_DEVICE_STM32L0XX)
//mosi D11 PA7
//cs D10 PB6
//reset D12 PA6
//SPI_CLK D13   PA5
//A0 ou DC pin D7 PA8

/** SPI port number e.g SPI1, SPI2 (not to be confused with GPIOA, GPIOB, etc) */
#define CONTROLLER_SPI_NUMBER      SPI1
#define CONTROLLER_SPI_PORT        GPIOA

//CLOCK
#define CONTROLLER_SPI_SCK_PIN     GPIO_PIN_5
//#define CONTROLLER_SPI_SCK_PINSRC  GPIO_PinSource5

//MISO Non utilisée
//#define CONTROLLER_SPI_MISO_PIN    GPIO_PIN_6
//#define CONTROLLER_SPI_MISO_PINSRC GPIO_PinSource6

//MOSI
#define CONTROLLER_SPI_MOSI_PIN    GPIO_PIN_7
//#define CONTROLLER_SPI_MOSI_PINSRC GPIO_PinSource7

//Slave Select
#define CONTROLLER_SPI_SS_PORT  GPIOB
#define CONTROLLER_SPI_SS_PIN   GPIO_PIN_6

//DC pin correspondrait à A0, register select
#define CONTROLLER_SPI_DC_PORT  GPIOA
#define CONTROLLER_SPI_DC_PIN   GPIO_PIN_8

//Reset ok
#define CONTROLLER_SPI_RST_PORT GPIOA
#define CONTROLLER_SPI_RST_PIN  GPIO_PIN_6



#define GLCD_SELECT()     HAL_GPIO_WritePin(CONTROLLER_SPI_SS_PORT,CONTROLLER_SPI_SS_PIN, GPIO_PIN_RESET) //0
#define GLCD_DESELECT()   HAL_GPIO_WritePin(CONTROLLER_SPI_SS_PORT,CONTROLLER_SPI_SS_PIN,GPIO_PIN_SET)  //1
#define GLCD_A0_LOW()     HAL_GPIO_WritePin(CONTROLLER_SPI_DC_PORT,CONTROLLER_SPI_DC_PIN,GPIO_PIN_RESET) //0
#define GLCD_A0_HIGH()    HAL_GPIO_WritePin(CONTROLLER_SPI_DC_PORT,CONTROLLER_SPI_DC_PIN,GPIO_PIN_SET) //1
#define GLCD_RESET_LOW()  HAL_GPIO_WritePin(CONTROLLER_SPI_RST_PORT,CONTROLLER_SPI_RST_PIN, GPIO_PIN_RESET)// 0
#define GLCD_RESET_HIGH() HAL_GPIO_WritePin(CONTROLLER_SPI_RST_PORT,CONTROLLER_SPI_RST_PIN,GPIO_PIN_SET)//  1

#else
	#error "Controller not supported by STM32L0XX"
#endif

#endif
