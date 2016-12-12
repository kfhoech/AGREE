/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.4
 */
#ifndef __SEQUENCE_NUMBERED_RGB_LED_SETTING_TYPES_H__
#define __SEQUENCE_NUMBERED_RGB_LED_SETTING_TYPES_H__
#ifdef __cplusplus
extern "C" {
#endif
#include "ivory.h"
#include "ivory_serialize.h"
#include "sequence_num_types.h"
#include "rgb_led_setting_types.h"
typedef struct sequence_numbered_rgb_led_setting {
            uint32_t seqnum;
            struct rgb_led_setting val;
        } sequence_numbered_rgb_led_setting;
void sequence_numbered_rgb_led_setting_get_le(const uint8_t *n_var0, uint32_t n_var1, struct sequence_numbered_rgb_led_setting *n_var2);
void sequence_numbered_rgb_led_setting_get_be(const uint8_t *n_var0, uint32_t n_var1, struct sequence_numbered_rgb_led_setting *n_var2);
void sequence_numbered_rgb_led_setting_set_le(uint8_t *n_var0, uint32_t n_var1, const struct sequence_numbered_rgb_led_setting *n_var2);
void sequence_numbered_rgb_led_setting_set_be(uint8_t *n_var0, uint32_t n_var1, const struct sequence_numbered_rgb_led_setting *n_var2);

#ifdef __cplusplus
}
#endif
#endif /* __SEQUENCE_NUMBERED_RGB_LED_SETTING_TYPES_H__ */