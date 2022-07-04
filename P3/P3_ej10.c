/*
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    P3_ej10.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL43Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
#define TEMPO 200000
#define TOGGLE_RED GPIOE->PTOR |= 1<<31
#define TOGGLE_GREEN GPIOD->PTOR |= 1<<5
#define ON_RED GPIOE->PCOR |= 1<<31
#define ON_GREEN GPIOD->PCOR |= 1<<5
#define OFF_RED GPIOE->PSOR |= 1<<31
#define OFF_GREEN GPIOD->PSOR |= 1<<5
#define LECTURA_SW1 GPIOA->PDIR & 1<<4
typedef enum{
	APAGADOS, BLYNKING
}estados_mef;
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif
    //LED VERDE
    SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
    PORTD->PCR[5] |= PORT_PCR_MUX(1);
    GPIOD->PCOR |= 1<<5;
    GPIOD->PDDR |= 1<<5;
    //LED ROJO
    SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
    PORTE->PCR[31] |= PORT_PCR_MUX(1);
    GPIOE->PCOR |= 1 << 31;
    GPIOE->PDDR |= 1 << 31;

    //SW1
    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
    PORTA->PCR[4] |= PORT_PCR_MUX(1);
    GPIOA->PDDR &= ~(1<<4);
    PORTA->PCR[4] |= 0x3; // PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;

    //Arranco apagado los led
    GPIOE->PSOR |= 1<<31;
    volatile estados_mef estado_actual = APAGADOS;
    volatile estados_mef proximo_estado = APAGADOS;
    volatile static int i = 0;
    while(1) {
    	switch (estado_actual){
    	case APAGADOS:
    		OFF_GREEN;
    		OFF_RED;
    		if(!(LECTURA_SW1)){
    			proximo_estado = BLYNKING;
    			ON_RED;
    			i = TEMPO;
    		}
    		break;
    	case BLYNKING:
    		if(i > 0)
    			i--;
    		if(i == 0){
    			TOGGLE_RED;
    			TOGGLE_GREEN;
    			i = TEMPO;
    		}
    		if (LECTURA_SW1)
    			proximo_estado = APAGADOS;
    		break;
    	}
    	if (estado_actual != proximo_estado)
    		estado_actual = proximo_estado;
    }
    return 0 ;
}
