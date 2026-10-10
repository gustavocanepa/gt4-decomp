#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0057F238(s32, s32);
struct func_0042AB50_arg0 {
    s32 unk0;
    char pad4[0x4];
    f32 unk8;
    char padC[0x8];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

void func_0042AB50(struct func_0042AB50_arg0 *arg0, s32 arg1, f32 fparg0) {
    s32 temp_s1;
    temp_s1 = arg0->unk18;
    if ((temp_s1 == 1) && (func_0057F238(arg1, arg0->unk14) == 0)) {
        arg0->unk1C = temp_s1;
        arg0->unk8 = fparg0;
        arg0->unk0 = temp_s1;
    }
}
