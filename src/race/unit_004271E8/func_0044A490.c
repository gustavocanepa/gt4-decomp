#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688350[];
struct func_0044A490_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_0044A490(struct func_0044A490_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk4 = (s32)D_00688350;
    temp_v1 = arg0->unk0;
    if (temp_v1 != 0) {
        func_00575DA0(temp_v1);
    }
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
