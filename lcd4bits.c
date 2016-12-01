/*           User           */
/* Base didatica de LCD 16x2*/


#include "lcd4bits.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/**********************************/
/*        Defenir Macros          */
#define SET_E() (LCD_PORT|=LCD_EN)
#define SET_RS() (LCD_PORT|=LCD_RS)
#define SET_RW() (LCD_PORT|=LCD_RW)

#define CLEAR_E() (LCD_PORT&=~LCD_EN)
#define CLEAR_RS() (LCD_PORT&=~LCD_RS)
#define CLEAR_RW() (LCD_PORT&=~LCD_RW)

void lcdcmd(unsigned char Data)
{

CLEAR_RS(); 
CLEAR_E();
CLEAR_RW();
LCD_PORT &= 0x0f; //00001111

LCD_PORT |= ((Data ) & 0xf0); //11110000
CLEAR_RW();
SET_E();
_delay_ms(2);
CLEAR_E();

LCD_PORT &= 0x0f; //11110000

LCD_PORT  |= ((Data<<4) &  0xf0); //11110000
SET_E();
_delay_ms(2);
CLEAR_E();


}

void lcdInit(void)
{
CLEAR_RS();
CLEAR_E();
CLEAR_RW();
LCD_PORT |= 0x30; //00110000
_delay_ms(40);
SET_E();
CLEAR_E();
_delay_ms(2);

LCD_PORT &= 0x20; //00100000
SET_E();
CLEAR_E();
lcdcmd(0x28);   // set tamanho dados 4 bit 2 linhas 00101000
_delay_ms(50);
lcdcmd(0x0E);   // set cursor do display e sintila 00001110
_delay_ms(50);
lcdcmd(0x01); // limpa lcd 00000001
_delay_ms(50);
lcdcmd(0x06);  // cursor shift direcção 00000110
_delay_ms(50);
lcdcmd(0x80);  //set endereço ram 10000000
_delay_ms(50);
}
void gotoXy(unsigned char  x,unsigned char y)
{
 if(x<40) //01000000
 {
  if(y) x |= 0x40; //01000000
  x |=0x80; //10000000
  lcdcmd(x);
  }

}

void lcdData(unsigned char dados)
{
SET_RS();  
CLEAR_RW();
CLEAR_E();
LCD_PORT &= 0x0f; //00001111
LCD_PORT |=((dados ) & 0xf0); //11110000
CLEAR_RW();
SET_E();
_delay_ms(2);
CLEAR_E();
LCD_PORT &= 0x0f; //00001111
LCD_PORT  |= ((dados<<4) &  0xf0);//11110000
SET_E();
_delay_ms(2);
CLEAR_E();
}
void lcdPrints(const char *s)
  {

    while (*s)
      {
	 lcdData(*s);
	 s++;
      }
  }

