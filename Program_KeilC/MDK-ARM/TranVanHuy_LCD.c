#include "main.h"
#define LCD4bit

#ifdef LCD8bit
// LCD put 8 bit DATA - 8 bit mode
void LCD_put(uint8_t ch) {
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port,LCD_D7_Pin,(GPIO_PinState)(ch&0x80));
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port,LCD_D6_Pin,(GPIO_PinState)(ch&0x40));
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port,LCD_D5_Pin,(GPIO_PinState)(ch&0x20));
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port,LCD_D4_Pin,(GPIO_PinState)(ch&0x10));
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port,LCD_D3_Pin,(GPIO_PinState)(ch&0x08));
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port,LCD_D2_Pin,(GPIO_PinState)(ch&0x04));
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port,LCD_D1_Pin,(GPIO_PinState)(ch&0x02));
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port,LCD_D0_Pin,(GPIO_PinState)(ch&0x01));
	HAL_GPIO_WritePin(LCD_E_GPIO_Port,LCD_E_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port,LCD_E_Pin,GPIO_PIN_RESET);
	HAL_Delay(1);
}
// 8 bit mode INIT
void LCD_init() {
	HAL_GPIO_WritePin(LCD_E_GPIO_Port,LCD_E_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port,LCD_RS_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port,LCD_RW_Pin,GPIO_PIN_RESET);
	HAL_Delay(15);
	LCD_put(0x30);
	HAL_Delay(5);
	LCD_put(0x30);
	LCD_put(0x30);
	LCD_put(0x38); // N = 1, F = 0
	LCD_put(0x08);
	LCD_put(0x01);
	LCD_put(0x06); // ID=1 ; S=0
	// End of LCD initilization
	LCD_put(0x0D); // Display = ON; Blink = ON
}
#endif

#ifdef LCD4bit
void LCD_put4bit(uint8_t ch) {
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port,LCD_RW_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port,LCD_D7_Pin,(GPIO_PinState)(ch&0x80));
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port,LCD_D6_Pin,(GPIO_PinState)(ch&0x40));
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port,LCD_D5_Pin,(GPIO_PinState)(ch&0x20));
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port,LCD_D4_Pin,(GPIO_PinState)(ch&0x10));
	HAL_GPIO_WritePin(LCD_E_GPIO_Port,LCD_E_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port,LCD_E_Pin,GPIO_PIN_RESET);
}
void LCD_put(uint8_t ch) {
	LCD_put4bit(ch);
	LCD_put4bit(ch<<4);
	HAL_Delay(1);
}
void LCD_init(void) {   // 4 bit mode
	HAL_Delay(15);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port,LCD_RS_Pin,GPIO_PIN_RESET);
	LCD_put4bit(0x30);
	HAL_Delay(5);
	LCD_put4bit(0x30);
	HAL_Delay(1);
	LCD_put4bit(0x30);
	HAL_Delay(1);
	LCD_put4bit(0x20); 
	HAL_Delay(1);
	LCD_put(0x28); // N=1; F=0
	LCD_put(0x08);
	LCD_put(0x01);
	LCD_put(0x06); // ID=1 ; S=0
	// End of LCD initilization
	LCD_put(0x0D); // Display = ON; Blink = ON
}
#endif

void LCD_putchar(uint8_t ch) {
		HAL_GPIO_WritePin(LCD_RS_GPIO_Port,LCD_RS_Pin,GPIO_PIN_SET);
		LCD_put((uint8_t)ch);
}

void LCD_putcmd(uint8_t cmd) {
		HAL_GPIO_WritePin(LCD_RS_GPIO_Port,LCD_RS_Pin,GPIO_PIN_RESET);
		LCD_put(cmd);
}
void LCD_printf(uint8_t *s, uint8_t StringEndChar) {
	uint8_t i=0;
	while(*(s+i) != StringEndChar) {
		if (*(s+i) != '\n') 
			LCD_putchar(*(s+i));
		else
			LCD_putcmd(0x80+0x40); // New line character
		i = i + 1;
	}
}

void LCD_gotoXY(uint8_t X, uint8_t Y) {	
	LCD_putcmd(0x80+0x40*Y + X);
}

void LCD_setCGRAM(uint8_t *s, uint8_t pos) 
{
	for (uint8_t i=0;i<8;i++) {
		LCD_putcmd(0x40 + (pos<<3) + i); // CGRAM Address
		LCD_putchar(*(s+i));
	}
}
