#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Label_x
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_x = obj;
            lv_obj_set_pos(obj, 38, 47);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "X");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Display_x
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.display_x = obj;
            lv_obj_set_pos(obj, 94, 51);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "000.000");
            lv_obj_set_style_text_font(obj, &ui_font_segments7, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Display_x_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.display_x_1 = obj;
            lv_obj_set_pos(obj, 94, 51);
            lv_obj_set_size(obj, 210, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "000.000");
            lv_obj_set_style_text_font(obj, &ui_font_segments7, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffa0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Label_y
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_y = obj;
            lv_obj_set_pos(obj, 39, 101);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Y");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Display_y
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.display_y = obj;
            lv_obj_set_pos(obj, 94, 100);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "000.000");
            lv_obj_set_style_text_font(obj, &ui_font_segments7, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Label_z
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_z = obj;
            lv_obj_set_pos(obj, 39, 153);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Z");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Display_z
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.display_z = obj;
            lv_obj_set_pos(obj, 94, 153);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "000.000");
            lv_obj_set_style_text_font(obj, &ui_font_segments7, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_main() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
