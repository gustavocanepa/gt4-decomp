#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0055FAF8(s32, void *);                 /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00689BB0[];
struct func_0055F738_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC8];
    s32 unkD0;
};

void func_0055F738(struct func_0055F738_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unkD0 = (s32)D_00689BB0;
    temp_v1 = arg0->unk4;
    if (temp_v1 != 0) {
        func_0055FAF8(temp_v1, arg0);
    }
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
