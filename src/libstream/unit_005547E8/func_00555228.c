#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005B72A8();                                /* extern */

struct func_00555228_arg0 {
    char pad0[0x4F0];
    s32 unk4F0;
    s32 unk4F4;
};

void func_00555228(struct func_00555228_arg0 *arg0) {
    s32 temp_a0;
    s32 temp_v0;

    temp_a0 = func_005B72A8();
    temp_v0 = arg0->unk4F0 + 1;
    arg0->unk4F0 = temp_v0;
    if (temp_v0 == 1) {
        arg0->unk4F4 = temp_a0;
    }
}
