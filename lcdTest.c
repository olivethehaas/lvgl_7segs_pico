#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/dma.h"
#include "hardware/pio.h"
#include "hardware/pwm.h"
#include "ui/screens.h"
#include "ili9341.h"
#include "xpt2046.h"
#include "lvgl.h"
//#include "ui/ui.h"
//#include "demos/lv_demos.h"
//#include "examples/lv_examples.h"

// static lv_color32_t buf1[240 * 320 / 10];
// static lv_color32_t buf2[240 * 320 / 10];
#define LED_PIN 2

static lv_draw_buf_t *buf1;
static lv_draw_buf_t *buf2;
static lv_obj_t *screen;
static void value_changed_event_cb(lv_event_t * e);
char string_x[8];
float my_float = 0.000f;
int main()
{
    stdio_init_all();

    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(LED_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.f);
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(LED_PIN, 255);

    ili9341_Init(LCD_LANDSCAPE);
    xpt2046_Init(TP_LANDSCAPE);

    lv_init();

    lv_display_t *disp = lv_display_create(480	, 320);
    lv_display_set_flush_cb(disp, lcd_Flash_CB);
    buf1 = lv_draw_buf_create(240, 60, LV_COLOR_FORMAT_RGB565, LV_STRIDE_AUTO);
    buf2 = lv_draw_buf_create(240, 60, LV_COLOR_FORMAT_RGB565, LV_STRIDE_AUTO);
    lv_display_set_draw_buffers(disp, buf1, buf2);
    // lv_display_set_buffers(disp, buf1, buf2, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);
    lv_display_set_render_mode(disp, LV_DISPLAY_RENDER_MODE_PARTIAL);
    screen = lv_obj_create(NULL);

    lv_indev_t *indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, xpt2046_read_cb);
    lv_screen_load(screen);
    ui_init();

    while (1)
    {
        sleep_ms(1);
        sprintf(string_x, "%6.3f", my_float);
        lv_label_set_text(objects.display_x_1, string_x);
        lv_obj_set_style_text_align(objects.display_x_1, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        my_float += 0.001f;
        lv_timer_handler();
        lv_tick_inc(1);

    }
}

