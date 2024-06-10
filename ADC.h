/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: ADC.h
 *
 * Description: Header file for the ADC driver
 *
 * Author: Omar Talaat
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

typedef enum{
	Vref,
	Vcc,
	Vint=3
}ADC_ReferenceVolatge;

typedef enum{
	F_CPU_2=2,
	F_CPU_4=4,
	F_CPU_8=8,
	F_CPU_16=16,
	F_CPU_32=32,
	F_CPU_64=64,
	F_CPU_128=128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initiate the ADC
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);



/*
 * Description :
 * Start the conversion and interrupt will get the result
 */
uint16 ADC_readChannel(uint8 ch_num);



#endif /* ADC_H_ */
