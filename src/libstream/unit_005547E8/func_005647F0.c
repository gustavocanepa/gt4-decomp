#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005ADCC0(s32);                         /* extern */
s32 func_005ADCE0(s32);                         /* extern */

struct func_005647F0_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x8];
    s32 unk18;
    char pad1C[0x4];
    s32 unk20;
};

s32 func_005647F0(struct func_005647F0_arg0 *arg0) {
    s32 temp_s1;

    func_005ADCE0(arg0->unk20);
    temp_s1 = arg0->unk18 == arg0->unkC;
    func_005ADCC0(arg0->unk20);
    return temp_s1;
}
