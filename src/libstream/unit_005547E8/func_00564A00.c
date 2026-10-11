#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005ADCC0(s32);                         /* extern */
s32 func_005ADCE0(s32);                         /* extern */

struct func_00564A00_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x4];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

void func_00564A00(struct func_00564A00_arg0 *arg0) {
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;

    func_005ADCE0(arg0->unk20);
    temp_v1 = arg0->unk18;
    if (temp_v1 != 0) {
        temp_v0 = arg0->unk14 + 1;
        arg0->unk18 = (s32) (temp_v1 - 1);
        arg0->unk14 = temp_v0;
        if (temp_v0 == arg0->unkC) {
            arg0->unk14 = 0;
        }
    }
    func_005ADCC0(arg0->unk20);
    temp_v1_2 = arg0->unk1C;
    if (temp_v1_2 != -1) {
        func_005ADCC0(temp_v1_2);
    }
}
