/*
 * KL43.cpp
 */

#include "KL43.h"

void board_init(void){
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif
}
void ledRed_init(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE->PCR[31] = PORT_PCR_MUX(1);
	LED_RED_OFF;
	GPIOE->PDDR |= 1<<31;
}
void ledGreen_init(void){
    SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
    PORTD->PCR[5] |= PORT_PCR_MUX(1);
    LED_GREEN_OFF;
    GPIOD->PDDR |= 1 << 5;
}
void pulsadorSw1_init(void){
    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
    PORTA->PCR[4] |= PORT_PCR_MUX(1);
    GPIOA->PDDR &= ~(1<<3);
    PORTA->PCR[4] |= 0x3;
}
void pulsadorSw3_init(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	PORTC->PCR[3] |= PORT_PCR_MUX(1);
	GPIOC->PDDR &= ~(1 << 3);
	PORTC-> PCR[3] |= 0x3;
}
uint8_t pulsadorSw1_get(void){
	return (GPIOA->PDIR & (1 << 4))?0:1;
}
uint8_t pulsadorSw3_get(void){
	return (GPIOC->PDIR & (1 << 3))?0:1;
}
