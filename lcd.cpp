#include "lcd.h"

void init_display() {
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
}

void clear_lcd() {
    BSP_LCD_Clear(LCD_COLOR_BLACK);
}

void blink_text() {
    BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
    BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"AHOJ SVETE!", CENTER_MODE);
    HAL_Delay(WAIT_TIME);
    BSP_LCD_ClearStringLine(0);
    HAL_Delay(WAIT_TIME);
}

void button_text() {
        BSP_LCD_SetTextColor(LCD_COLOR_RED);
        BSP_LCD_DisplayStringAt(0, 50, (uint8_t *)"TLACITKO!!!!!!", CENTER_MODE);
        HAL_Delay(WAIT_TIME);
        BSP_LCD_ClearStringLine(2);
}