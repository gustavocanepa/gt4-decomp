#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00454598();                                /* extern */

struct func_005FA890_arg0 {
    char pad0[0x15];
    u8 unk15;
};

void func_005FA890(struct func_005FA890_arg0 *arg0, s32 arg1, s32 (*arg2)(s32, s32)) {
    if (!(arg0->unk15 & 1 & 0xFF)) {
        arg2(arg1, func_00454598());
    }
}
