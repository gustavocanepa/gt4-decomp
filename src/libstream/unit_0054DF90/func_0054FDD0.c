#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00563408(s32);
s32 func_005ADCA0(s32);                         /* extern */
s32 func_005ADF20(s32);                     /* extern */

extern char D_006C84E8[];
struct func_0054FDD0_arg0 {
    char pad0[0x24];
    s32 unk24;
    s32 unk28;
    char pad2C[0xC];
    s32 unk38;
    s32 unk3C;
};

void func_0054FDD0(struct func_0054FDD0_arg0 *arg0, s32 arg1) {
    func_005A48D8(arg0, 0, 0x44);
    arg0->unk3C = arg1;
    arg0->unk28 = (s32) ((func_00563408(1) & 0x0FFFFFFF) | 0x20000000);
    arg0->unk24 = func_00563408(2);
    func_005ADF20(0);
    arg0->unk38 = func_005ADCA0((s32)D_006C84E8);
}
