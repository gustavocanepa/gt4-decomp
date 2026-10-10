/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_005851F0(s32);                           /* extern */
s32 func_005B72A8();                                /* extern */
s32 func_005B72F8();                            /* extern */

struct func_005840C0_temp_v0 {
    char pad0[0x4];
    u32 unk4;
    u32 unk8;
};

s32 func_005840C0(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 temp_s3;
    s32 var_s0;
    u32 temp_v0_2;
    struct func_005840C0_temp_v0 *temp_v0;

    temp_s3 = func_005B72A8();
    temp_v0 = func_005851F0(arg0);
    if (temp_v0 != NULL) {
        temp_v0_2 = temp_v0->unk4;
        var_s0 = temp_v0_2 & 1;
        if (arg1 != NULL) {
            *arg1 = (temp_v0_2 >> 1) << 8;
        }
        if (arg2 != NULL) {
            *arg2 = ((u32) temp_v0->unk8 >> 1) << 8;
        }
    } else {
        var_s0 = 0x8105000E;
        if (arg1 != NULL) {
            *arg1 = 0;
        }
        if (arg2 != NULL) {
            *arg2 = 0;
        }
    }
    if (temp_s3 != 0) {
        func_005B72F8();
    }
    return var_s0;
}
