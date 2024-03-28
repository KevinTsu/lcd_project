#include <stdio.h>

int ledsta = 0;
void ledset(int sta) {
}

typedef struct {
    int sta;
    void (*setsta)(int sta);
}LedObj;

void drv_led1_setsta(int sta) {
}

LedObj LED1 = {
    .sta = 0,
    .setsta = drv_led1_setsta,
};

void drv_led2_setsta(int sta) {
}

LedObj LED2 = {
    .sta = 0,
    .setsta = drv_led2_setsta,
};

void ledset(LedObj *led, int sta) {
    led->setsta(sta);
}

/*
 *Framework
 *GUI layer
 *LCD driver layer dev_lcd.c dev_lcd.h
 *IC driver layer dev_str7565.c & dev_str7565.h dev_ILI9341.c & dev_ILI9341.h
 *Interface layer mcu_spi.c & mcu_spi.h stm324xg_eval_fsmc_sram.c & stm324xg_eval_fsmc_sram.h
 */

/*
 * device : attribute
 * diver  : method
 */

// driver
typedef struct {
    // ID :driver and device bond.
    int id;

    int (*init)(DevLcd *lcd);
    int (*draw_point)(DevLcd *lcd, int x, int y, int color);
    int (*color_fill)(DevLcd *lcd, int sx,int ex,int sy,int ey, int color);
    int (*fill)(DevLcd *lcd, int sx,int ex,int sy,int ey,int *color);
    int (*onoff)(DevLcd *lcd, int sta);
    int (*prepare_display)(DevLcd *lcd, int sx, int ex, int sy, int ey);
    void (*set_dir)(DevLcd *lcd, int scan_dir);
    void (*backlight)(DevLcd *lcd, int sta);
}_lcd_drv;

