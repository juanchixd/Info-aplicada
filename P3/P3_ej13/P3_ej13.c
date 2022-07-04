/**
 * @file    P3_ej13.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "KL43.h"
#include "MEF.h"
int main(void) {
	board_init();
	ledRed_init();
	ledGreen_init();
	pulsadorSw1_init();
	pulsadorSw3_init();
    while(1) {
    	mef();
    }
    return 0 ;
}
