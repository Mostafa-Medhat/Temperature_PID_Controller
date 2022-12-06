/*
 * TC72.h
 *
 *  Created on: Dec 7, 2022
 *      Author: RYZEN
 */

#ifndef TC72_H_
#define TC72_H_

#define CONTINUOUS_MODE	0X04
#define ONE_SHOT		0x14

void TC72_Init(unsigned char mode);

unsigned char TC72_ReadTemp(void);


#endif /* TC72_H_ */
