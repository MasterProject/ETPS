/*
 * MTPRESS.h
 *
 *  Created on: Apr 3, 2017
 *      Author: Issac
 */

#ifndef MTPRESS_H_
#define MTPRESS_H_

#include "MKL25Z4.h"
#include "Typedef.h"



extern void MTPRESS_vMain(void);

#define  true    1
#define  false   0


/* Adjust RED LED current balancing*/
#define BEAT_DETECTED					        2
#define LOW_PRESSURE							60


#endif /* MTPRESS_H_ */
