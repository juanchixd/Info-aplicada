/*
 * KL43.h
 */

#ifndef KL43_H_
#define KL43_H_

//==================[inclusions]======================
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL43Z4.h"
#include "fsl_debug_console.h"
//=================[cplusplus]========================
#ifdef __cplusplus
extern "C"{
#endif
//=================[macros]===========================
#define LED_RED_TOGGLE		GPIOE->PTOR |= 1 << 31
#define LED_RED_OFF			GPIOE->PSOR |= 1 << 31
#define LED_RED_ON			GPIOE->PCOR |= 1 << 31

#define LED_GREEN_TOGGLE	GPIOD->PTOR |= 1 << 5
#define LED_GREEN_OFF		GPIOD->PSOR |= 1 << 5
#define LED_GREEN_ON		GPIOD->PCOR |= 1 << 5

//=================[external functions definition]====
void board_init(void); //inicializar hardware
void ledRed_init(void); //inicializar led rojo
void ledGreen_init(void); //inicializar led verde
void pulsadorSw1_init(void); //inicializar sw1
void pulsadorSw3_init(void); //inicializar sw3
uint8_t pulsadorSw1_get(void); // return 1 pulsado, 0 no pulsado
uint8_t pulsadorSw3_get(void); // return 1 pulsado, 0 no pulsado
#ifdef __cplusplus
}
#endif

#endif /* KL43_H_ */
