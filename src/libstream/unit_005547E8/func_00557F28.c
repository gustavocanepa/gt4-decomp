#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00557EC0();                            /* extern */
s32 func_00578CF0(s32, s32);                /* extern */
s32 func_00611150(s32, s32);                /* extern */

struct func_00557F28_arg0 {
    char pad0[0x75C];
    s32 unk75C;
    s32 unk760;
    s32 unk764;
};

void func_00557F28(void *arg0) {
    func_00557EC0();
    func_00611150(arg0 + 0x630, 0xA000);
    ((struct func_00557F28_arg0 *)arg0)->unk75C = func_00578CF0(0x10, 0xA000);
    ((struct func_00557F28_arg0 *)arg0)->unk760 = func_00578CF0(0x40, 0x1400);
    ((struct func_00557F28_arg0 *)arg0)->unk764 = func_00578CF0(0x40, 0x2800);
}
