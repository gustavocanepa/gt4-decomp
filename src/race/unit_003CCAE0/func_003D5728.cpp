#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_003D51B0(s32, s32, s32, s32, s32, s32, f32, f32, f32, f32); /* extern */
s32 func_003D56C0();                                /* extern */

struct func_003D5728_arg0 {
    char pad0[0x12C8];
    s32 unk12C8;
    s32 unk12CC;
};

void func_003D5728(char *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    if (func_003D56C0() != 0) {
        func_003D51B0((s32)(arg0 + (arg1 * 0x320)), arg1, ((struct func_003D5728_arg0 *)arg0)->unk12C8, ((struct func_003D5728_arg0 *)arg0)->unk12CC, arg2, (s32)(arg0 + 0x12C0), fparg0, fparg1, fparg2, fparg3);
    }
}

}
