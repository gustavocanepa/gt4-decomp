#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00473718(s32, s32, s32);                   /* extern */

struct func_004790E8_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

void func_004790E8(struct func_004790E8_arg0 *arg0, s32 arg1) {
    if (arg0->unkC == 0) {
        arg0->unkC = func_00473718(arg1, arg0->unk0, arg0->unk4);
    }
}
