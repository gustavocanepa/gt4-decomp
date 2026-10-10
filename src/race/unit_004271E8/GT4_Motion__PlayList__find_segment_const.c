#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0042A510_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 GT4_Motion__PlayList__find_segment_const(struct func_0042A510_arg0 *arg0, s32 arg1, s32 arg2, f32 fparg0) {
    s32 mid;
    while (arg2 - arg1 >= 2) {
        mid = (arg1 + arg2) >> 1;
        if (fparg0 < M2C_FIELD((arg0->unk4 + (mid << 5)), f32 *, 4)) {
            arg2 = mid;
        } else {
            arg1 = mid;
        }
    }
    return arg1;
}
