#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0035E3F0(s32);                             /* extern */

struct func_003B4FA0_arg0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x11C8];
    s32 unk11E4;
};

void func_003B4FA0(struct func_003B4FA0_arg0 *arg0) {
    arg0->unk11E4 = func_0035E3F0(arg0->unk18);
}
