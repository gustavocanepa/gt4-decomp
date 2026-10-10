#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */

struct func_00407470_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_00407470(struct func_00407470_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 != 0) {
        func_00575DA0(temp_v0);
        arg0->unk4 = 0;
    }
}
