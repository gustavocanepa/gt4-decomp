#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00510C38(void *, u16, s32);            /* extern */

struct func_0050FA98_arg1 {
    char pad0[0x64];
    u16 unk64;
};

void func_0050FA98(s32 arg0, struct func_0050FA98_arg1 *arg1) {
    func_00510C38(arg1, arg1->unk64, arg0);
}
