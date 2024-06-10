/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: ADC.h
 *
 * Description: Source file for the ADC driver
 *
 * Author: Omar Talaat
 *
 *******************************************************************************/

#include "ADC.h"
#include <avr/interrupt.h> /* For ADC ISR */
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */

/*
 * Description :
 * Initiate the ADC
 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	/* Adjust Vref of ADC
	 * REFS0=0 , REFS1=0
	 */
	/* Right adjust the result
	 * ADLAR=0
	 */
	/* Select channel zero initially
	 * MUX0-4=0
	 */
	ADMUX=0;
	ADMUX|=((Config_Ptr->ref_volt)<<6);


	/*
	 * Enable ADC
	 * ADEN=1
	 */

	/*
	 * Choose ADC Freq to Config_Ptr->prescaler
	 */
	ADCSRA=(1<<ADEN)|Config_Ptr->prescaler;

}


/*
 * Description :
 * Start the conversion and interrupt will get the result
 */
uint16 ADC_readChannel(uint8 ch_num)
{
	/* Select channel */
	ADMUX=((ADMUX&0xE0)|(ch_num&0x07));

	/* Start Conversion */
	ADCSRA|=(1<<ADSC);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}



