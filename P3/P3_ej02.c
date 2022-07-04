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
 * @file    Ejercicio 2.c
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

void retardo(int num){
	for(int i=0; i < num * 1000; i++){
	}
}
#define TMAX 150000
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("Hello World\n");
    SIM->SCGC5 |= (1<<12);
    SIM->SCGC5 |= (1<<13);
    PORTE->PCR[31] |= (1<<8);
    PORTD->PCR[5] |= (1<<8);
    PTD->PCOR |= (1<<5);
    PTD->PDDR |= (1<<5);
    PTE->PCOR |= (1<<31);
    PTE->PDDR |= (1<<31);
	PTE->PSOR |= 1<<31;
	PTD->PSOR |= 1<<5;
	volatile static int TEMPO = 0;
    while(1) {
    	TEMPO++;
    	if(TEMPO< TMAX){
    		GPIOE->PSOR |= 1 <<	31;
    		GPIOD->PCOR |= 1 << 5;
    	}
    	if(TEMPO> TMAX){
    		GPIOE->PCOR |= 1 << 31;
    		GPIOD->PSOR |= 1 << 5;
    	}
    	if(TEMPO > (2*TMAX))
    		TEMPO=0;
//
//    	PTD->PCOR |= 1<<5;
//    	retardo(500);
//    	PTD->PSOR |= 1<<5;
//        PTE->PCOR |= 1<<31;
//        retardo(500);
//        PTE->PSOR |= 1<<31;
    }
    return 0 ;
}
