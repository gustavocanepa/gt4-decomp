/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0058D110(s32 arg0) {
    u32 temp_a0;

    temp_a0 = arg0 & 0xFF;
    return (((temp_a0 / 10U) * 6) + temp_a0) & 0xFF;
}
