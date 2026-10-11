#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005A48D8(s32, s32, s32);           /* extern */
s32 func_005ADCC0(s32);                         /* extern */
s32 func_005ADCE0(s32);                         /* extern */

struct func_00564728_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char pad1C[0x4];
    s32 unk20;
};

void func_00564728(struct func_00564728_arg0 *arg0) {
    func_005ADCE0(arg0->unk20);
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    func_005A48D8(arg0->unk0, 0, arg0->unk4);
    func_005ADCC0(arg0->unk20);
}
