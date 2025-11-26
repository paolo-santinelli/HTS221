/*
 * hst221.h
 *
 *  Created on: Nov 24, 2021
 *      Author: A. Cuoghi, P. Santinelli
 */

#ifndef FERMILIB_HST221_H_
#define FERMILIB_HST221_H_
#include "i2c.h"

// Calibration parameters
typedef struct
{
	int16_t H0_rH;
	int16_t H1_rH;
	int16_t H0_T0_OUT;
	int16_t H1_T0_OUT;

	int16_t T0_degC;
	int16_t T1_degC;
	int16_t T0_OUT;
	int16_t T1_OUT;

} calib_params;

// Temperature & Humidity
typedef struct
{
	int16_t  temp;
	uint16_t hum;
} temp_hum;


int16_t hst221Init(i2c_transaction *i2cTrans);
int16_t hst221ReadId(i2c_transaction *i2cTrans, uint8_t * id);					// Read who am I register to get
int16_t hst221ReadParams(i2c_transaction *i2cTrans,  calib_params * params);	// the Device identification code
int16_t hst221ReadTempHum(i2c_transaction *i2cTrans,  calib_params * params, temp_hum * tempHum);
#endif /* FERMILIB_HST221_H_ */
