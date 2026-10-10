#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005A38B0(s32, s32);                /* extern */
s32 func_005A3948(s8 *, s32);                   /* extern */
s8 *func_005A62C0(s32);                             /* extern */

struct func_005A49F8_arg0 {
    s32 unk0;
    char pad4[0x8];
    s32 unkC;
};

void func_005A49F8(struct func_005A49F8_arg0 *arg0, s8 *arg1) {
    s8 *temp_v0;

    if ((arg1 != NULL) && (*arg1 != 0)) {
        func_005A3948(arg1, arg0->unkC);
        func_005A3948((s8 *)(s32)": ", arg0->unkC);
    }
    temp_v0 = func_005A62C0(arg0->unk0);
    if (temp_v0 != NULL) {
        func_005A3948(temp_v0, arg0->unkC);
    }
    func_005A38B0(0xA, arg0->unkC);
}
