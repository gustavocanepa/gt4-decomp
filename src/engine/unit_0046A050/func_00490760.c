#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004906C8(void *, f32);                 /* extern */
f32 func_00490830();                                /* extern */

struct func_00490760_arg0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x18];
    s32 unk30;
    char pad34[0x34];
    s32 unk68;
    char pad6C[0xC];
    s32 unk78;
};

void func_00490760(struct func_00490760_arg0 *arg0) {
    if ((arg0->unk14 != 0) && (arg0->unk68 != 0)) {
        arg0->unk30 = 0;
        func_004906C8(arg0, func_00490830());
        arg0->unk78 = 0;
    }
}
