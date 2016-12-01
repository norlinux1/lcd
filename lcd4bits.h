#ifndef __lcd4bits_h_
#define __lcd4bits_h_


#include <avr/io.h>

#define LCD_PORT PORTD // aqui podemos mudar o LCD_PORT que pretendemos
#define LCD_RS  0x01 //0x01 ->00000001 PINO 0
#define LCD_RW  0x02 //0x02 ->00000010 PINO 1
#define LCD_EN  0x04 //0x04 ->00000100 PINO 2
void gotoXy(unsigned char  ,unsigned char);
void lcdInit(void);
void lcdCmd(unsigned char);
void lcdData(unsigned char);
void lcdPrints(const char * message);
#endif
