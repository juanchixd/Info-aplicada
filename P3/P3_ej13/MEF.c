/*
 * MEF.c
 *      Author: juan
 */
#include "MEF.h"

void mef(){
	static estados_t estado_actual = contando, proximo_estado;
	static uint8_t secuencia[N_SIM], press_SW1 = 0, press_SW3 = 0;
	static uint16_t i = 0;
	static uint32_t temp = 0;
	proximo_estado = estado_actual;
	switch(estado_actual){
		case contando:
			if (pulsadorSw1_get() && !(press_SW1)){
				press_SW1 = pulsado;
			}
			if (!pulsadorSw1_get() && press_SW1){
				press_SW1 = despulsado;
				secuencia[i++] = g;
			}
			if (pulsadorSw3_get() && !(press_SW3)){
				press_SW3 = pulsado;
			}
			if (!pulsadorSw3_get() && press_SW3){
				press_SW3 = despulsado;
				secuencia[i++] = r;
			}
			if(i == N_SIM){
				i=0;
				proximo_estado = encendiendo;
			}
			break;
		case encendiendo:
			if(i == N_SIM){
				i = 0;
				proximo_estado = contando;
				break;
			}
			if(secuencia[i] == r){
				LED_RED_ON;
				proximo_estado = red;
			}
			if(secuencia[i] == g){
				LED_GREEN_ON;
				proximo_estado = green;
			}
			break;
		case red:
			temp++;
			if(temp == T_ON){
				LED_RED_OFF;
			}
			if(temp == T_ON + T_OFF){
				temp = 0;
				i++;
				proximo_estado = encendiendo;
			}
			break;
		case green:
			temp++;
			if(temp == T_ON){
				LED_GREEN_OFF;
			}
			if(temp == T_ON + T_OFF){
				temp = 0;
				i++;
				proximo_estado = encendiendo;
			}
			break;
	}
	if(estado_actual != proximo_estado){
		estado_actual = proximo_estado;
	}
}
