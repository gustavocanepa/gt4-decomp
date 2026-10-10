#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004291A8(void *, s16, s16, s16, s32, f32, s32, s32, s32, f32, s32); /* extern */
s32 func_0042A220();                                /* extern */

struct func_004294E0_arg0_unk4 {
    char pad0[0x1C];
    s32 unk1C;
};
struct func_004294E0_arg0 {
    char pad0[0x4];
    struct func_004294E0_arg0_unk4 *unk4;
};
struct func_004294E0_temp_v0 {
    char pad0[0x4];
    s16 unk4;
    s16 unk6;
    s16 unk8;
};

s32 func_004294E0(struct func_004294E0_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 fparg0, f32 fparg1) {
    struct func_004294E0_temp_v0 *temp_v0;

    if (func_0042A220() != 1) {
        return 0;
    }
    temp_v0 = (arg1 * 0x10) + arg0->unk4->unk1C;
    return func_004291A8(arg0, temp_v0->unk4, temp_v0->unk6, temp_v0->unk8, arg2, fparg0, 3, arg3, arg4, fparg1, arg5);
}
