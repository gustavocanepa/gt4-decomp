#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0055FAB0(s32, void *);                 /* extern */
s32 func_0055FAF8(s32, void *);                 /* extern */

struct func_0055F9A0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_0055F9A0(struct func_0055F9A0_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 != 0) {
        func_0055FAF8(temp_v0, arg0);
    }
    arg0->unk4 = arg1;
    if (arg1 != 0) {
        func_0055FAB0(arg1, arg0);
    }
}
