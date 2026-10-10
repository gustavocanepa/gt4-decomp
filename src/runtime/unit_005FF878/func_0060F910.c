#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00504270(s32, void *, s32);            /* extern */

struct func_0060F910_arg0 {
    char pad0[0x24];
    s32 unk24;
};

void func_0060F910(void *arg0) {
    func_00504270(arg0 + 0xC, arg0 + 0x14, ((struct func_0060F910_arg0 *)arg0)->unk24);
}
