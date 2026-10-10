#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00454598();                                /* extern */
s32 func_00454650(void *, s32);                     /* extern */

struct func_005FA820_arg0 {
    char pad0[0x15];
    u8 unk15;
    char pad16[0x66];
    s32 unk7C;
};

s32 func_005FA820(struct func_005FA820_arg0 *arg0, s32 (*arg1)(s32)) {
    if (arg0->unk15 & 1 & 0xFF) {
        return arg0->unk7C;
    }
    return func_00454650(arg0, arg1(func_00454598()));
}
