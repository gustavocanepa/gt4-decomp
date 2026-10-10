#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0025B2E0(s32, f32);                    /* extern */
s32 func_002D23B0(void *);                          /* extern */

struct func_002D2DE0_temp_s1 {
    char pad0[0x14];
    f32 unk14;
};

struct func_002D2DE0_arg0 {
    char pad0[0xC0];
    s32 unkC0;
};

s32 func_002D2DE0(void *arg0) {
    s32 temp_s2;
    s32 temp_v0;
    struct func_002D2DE0_temp_s1 *temp_s1;

    temp_s1 = arg0 + 0xC4;
    temp_s2 = func_002D23B0(temp_s1);
    temp_v0 = ((struct func_002D2DE0_arg0 *)arg0)->unkC0;
    if (temp_v0 != 0) {
        func_0025B2E0(temp_v0, -temp_s1->unk14);
    }
    return temp_s2;
}
