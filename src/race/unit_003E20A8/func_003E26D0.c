#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003E44E8(s32, s32, s32, s32);              /* extern */

struct func_003E26D0_arg1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_003E26D0(s32 arg0, struct func_003E26D0_arg1 *arg1) {
    if (arg1->unkC == 0) {
        arg1->unkC = func_003E44E8(arg1->unk4, arg0, arg1->unk0, arg1->unk8);
    }
}
