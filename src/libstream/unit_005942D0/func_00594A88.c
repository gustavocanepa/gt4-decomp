/* libio (GNU iostream library, gcc 2000-10-03 snapshot): func_00594A88.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */

struct func_00594A88_arg0 {
    s32 unk0;
    char pad4[0x18];
    s32 unk1C;
    s32 unk20;
};

s32 func_00594A88(struct func_00594A88_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = arg0->unk1C;
    if (temp_a0 != 0) {
        if (!(arg0->unk0 & 1)) {
            func_00575DA0(temp_a0);
        }
    }
    arg0->unk1C = arg1;
    arg0->unk20 = arg2;
    if (arg3 != 0) {
        var_v0 = arg0->unk0 & ~1;
    } else {
        var_v0 = arg0->unk0 | 1;
    }
    arg0->unk0 = var_v0;
}
