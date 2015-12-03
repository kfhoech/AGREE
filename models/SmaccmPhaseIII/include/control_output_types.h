/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.2
 */
#ifndef __CONTROL_OUTPUT_TYPES_H__
#define __CONTROL_OUTPUT_TYPES_H__
#ifdef __cplusplus
extern "C" {
#endif
#include "ivory.h"
#include "ivory_serialize.h"
typedef struct control_output { bool armed;
                                float throttle;
                                float roll;
                                float pitch;
                                float yaw;
} control_output;
void control_output_get_le (const uint8_t * n_var0, uint32_t n_var1, struct control_output * n_var2);
void control_output_get_be (const uint8_t * n_var0, uint32_t n_var1, struct control_output * n_var2);
void control_output_set_le (uint8_t * n_var0, uint32_t n_var1, const struct control_output * n_var2);
void control_output_set_be (uint8_t * n_var0, uint32_t n_var1, const struct control_output * n_var2);

#ifdef __cplusplus
}
#endif
#endif /* __CONTROL_OUTPUT_TYPES_H__ */