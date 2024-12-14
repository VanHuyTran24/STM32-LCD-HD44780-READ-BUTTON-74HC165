#include <stdint.h>
#define LCD4bit

#ifdef LCD8bit
void LCD_put(uint8_t ch);
void LCD_init();
#endif

#ifdef LCD4bit
void LCD_put4bit(uint8_t ch);
void LCD_put(uint8_t ch);
void LCD_init(void);
#endif

void LCD_putchar(uint8_t ch);
void LCD_putcmd(uint8_t cmd);
void LCD_printf(uint8_t *s, uint8_t StringEndChar);
void LCD_gotoXY(uint8_t X, uint8_t Y);
void LCD_setCGRAM(uint8_t *s, uint8_t pos);