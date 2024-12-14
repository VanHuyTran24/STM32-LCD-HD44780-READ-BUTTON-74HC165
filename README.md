# STM32 LCD HD44780 Push Button Control with 74HC165

## Target

  <li>When pressing the SW1 button, the LCD display increases by one unit (for example, 00:00:00 -> 00:00:01, note that hours are displayed from 00-23, minutes and seconds are displayed from 00-59).</li>
  <li>When the SW2 button is pressed, the LCD displays a decrease of one unit.</li>
  <li>When button SW3 is pressed, LCD displays "00:00:00" again.</li>
  <li>When pressing button SW4, LCD automatically counts up from the current time. When pressing SW1, SW2 or SW3, counting stops.</li>

## Demo
![image](https://github.com/VanHuyTran24/STM32-LCD-HD44780-READ-BUTTON-74HC165/assets/166670555/195e9120-5f4f-4f40-95bb-b7a410783656)


Library File: [LCD.c](https://github.com/VanHuyTran24/STM32F103-LCD-HD44780-FULL-CONNECTION/blob/master/Program_KeilC/MDK-ARM/TranVanHuy_LCD.c) [LCD.h](https://github.com/VanHuyTran24/STM32F103-LCD-HD44780-FULL-CONNECTION/blob/master/Program_KeilC/MDK-ARM/TranVanHuy_LCD.c)

Source Code: [main.c](https://github.com/VanHuyTran24/STM32-LCD-HD44780-READ-BUTTON-74HC165/blob/master/Program_KeilC/Core/Src/main.c)
