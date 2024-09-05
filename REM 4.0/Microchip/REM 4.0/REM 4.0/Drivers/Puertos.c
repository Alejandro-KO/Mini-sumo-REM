/*
 * Puertos.c
 *
 * Created: 17/09/2023 10:29:00 p. m.
 *  Author: israa
 */ 
#include <avr/io.h>
#include "Puertos.h"

#define partestLED_PORTB_DATA_REG_BIT			( (uint8_t) 0x01 << 4 )
#define partestLED_PORTB_DIR_REG_BIT			( (uint8_t) 0x01 << 4 )
#define partestLED_ON							partestLED_PORTB_DIR_REG_BIT

static volatile uint8_t uCurrentLedOutputVa = ~partestLED_ON;


typedef unsigned short UBaseType_t;


/*void vSerialInit(void){
	DDRD=0x02;
	UCSR0A=0x00;
	UCSR0B=0x08;
	UCSR0C=0x06;
	UBRR0=0x0C;
}

void vWRITEChar( char data){	
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = data;
}*/

void vLEDInit_B(uint8_t bit_port_b)
{
    DDRB|=(1<<bit_port_b);
}

void vBUTTONInit_C(uint8_t bit_port_c)
{
    DDRC&=~(1<<bit_port_c);
    PORTC|=(1<<bit_port_c);
}

void vBUTTONInit_D(uint8_t bit_port_d)
{
    DDRD&=~(1<<bit_port_d);
    PORTD|=(1<<bit_port_d);
}

void vLEDToggle_B(uint8_t bit_port_b)
{
    PORTB^=(1<<bit_port_b);
}

void vLEDOn_B(uint8_t bit_port_b)
{
    PORTB|=(1<<bit_port_b);
}

void vLEDOff_B(uint8_t bit_port_b)
{
    PORTB&=~(1<<bit_port_b);
}

void vParTestToggleLED( UBaseType_t uxLED )
{
	/* There's only one LED on this board. */
	( void ) uxLED;

	/* Toggle user LED.
	The compound action is guaranteed to be not interrupted by other tasks. */
	vTaskSuspendAll();

	if ( uCurrentLedOutputVa == partestLED_ON )
	{
		/* Turn off. */
		DDRB |= partestLED_PORTB_DIR_REG_BIT;
		PORTB &= ~partestLED_PORTB_DIR_REG_BIT;
		uCurrentLedOutputVa = ~partestLED_ON;
	}
	else
	{
		/* Turn on. */
		DDRB |= partestLED_PORTB_DIR_REG_BIT;
		PORTB |= partestLED_PORTB_DIR_REG_BIT;
		uCurrentLedOutputVa = partestLED_ON;
	}

	xTaskResumeAll();
}