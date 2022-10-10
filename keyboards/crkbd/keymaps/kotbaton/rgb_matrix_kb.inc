RGB_MATRIX_EFFECT(vertical_gradient1)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

uint8_t rows[4][6] = {
    {18, 17, 12, 11, 4, 3},
    {19, 16, 13, 10, 5, 2},
    {20, 15, 14,  9, 6, 1},
    {-1, -1, -1,  8, 7, 0},
};

static bool vertical_gradient1(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t scale = scale8(64, rgb_matrix_config.speed);

    HSV hsv = rgb_matrix_config.hsv;
    for (uint8_t k = 0; k < 4; k++) {
        for (uint8_t j = 0; j < 6; j++) {
            uint8_t i = rows[k][j];
            if (i == -1)
                continue;

            RGB_MATRIX_TEST_LED_FLAGS();
            hsv.h = rgb_matrix_config.hsv.h + scale * k;
            RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
