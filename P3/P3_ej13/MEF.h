/*
 * MEF.h
 *
 *  Created on: 1 jul. 2022
 *      Author: juan
 */

#ifndef MEF_H_
#define MEF_H_
#include "KL43.h"

#define N_SIM 10
#define T_ON 50000
#define T_OFF 40000

typedef enum{
	despulsado, pulsado
}valoresPulsador_t;

typedef enum{
	r, g
}valoresLeds_t;

typedef enum{
	contando, encendiendo, red, green
}estados_t;

void mef(void);

#endif /* MEF_H_ */
