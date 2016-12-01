/*
 * Atmega8_LCD16x2.c
 *
 * Created: 01-12-2016 00:01:56
 *  Author: User
 */ 

#include <avr/io.h>
#include <stdio.h>

#define F_CPU 8000000UL
#include <stdio.h>		// sprintf
#include <util/delay.h>
#include "lcd4bits.h"
void Init_Hw()
{
	DDRC = 0xFE;				//11111110 defenir PORTC 0 como entrada, todo resto como saidas
	DDRD = 0xFF;				//11111111 tudo como saidas para o LCD
								//Configuração do ADC -> Falaremos desta configuração mais a frente
	ADCSRA=0X00;		
	ADMUX = 0x40;
	ADCSRA = 0x87;
}
int ler_AD(void)
{
	ADCSRA |= 0x40;				// inicia a conversão para Analogico0
	while(ADCSRA & 0x40);
	return ADC;
}
int main(void)
{
	
	char buffer[10];
	unsigned int Valor_AD;
	Init_Hw();									//Inicia a configuração do Hardware
	lcdInit();									//Inicia o LCD
	lcdPrints("  LCD ATMEGA8");
	while(1)
	{
		
		Valor_AD=ler_AD();
		gotoXy(2,1 );							//coloca o texto no 2ª posição do X e 1ª posição do Y
		sprintf(buffer, " ADC = %i ", Valor_AD); // falaremos nesta função em breve
		lcdPrints(buffer);						// envia resultado formatado para o LCD
		_delay_ms(200);
		
		
	}
}