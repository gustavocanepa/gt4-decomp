#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0042CD60(void *, s32);                 /* extern */
s32 func_0057F238(s32, s32);                        /* extern */

struct func_0042AAC0_arg0 {
    s32 unk0;
    char pad4[0x408];
    s32 unk40C;
    s32 unk410;
    s32 unk414;
};

void func_0042AAC0(struct func_0042AAC0_arg0 *arg0, s32 arg1) {
    if (arg0->unk410 != 0) {
        if (func_0057F238(arg1, arg0->unk414) == 0) {
            arg0->unk40C = 1;
            func_0042CD60(arg0, arg0->unk410);
            arg0->unk0 = 1;
        }
    } else {
        arg0->unk0 = 1;
    }
}
