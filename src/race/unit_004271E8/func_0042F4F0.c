#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005797A8(s32, s32, s32);       /* extern */

struct func_0042F4F0_arg0 {
    char pad0[0xB6C0];
    s32 unkB6C0;
};

s32 func_0042F4F0(struct func_0042F4F0_arg0 *arg0) {
    return arg0->unkB6C0 - func_005797A8(0x7D5, 4, 2);
}
