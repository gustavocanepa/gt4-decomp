#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001F1330();                                /* extern */
s32 func_005A609C(s32, s32);                    /* extern */

struct func_001DCA28_arg0 {
    char pad0[0x30];
    s32 unk30;
};

void func_001DCA28(void *arg0, s32 arg1, s32 arg2) {
    func_005A609C(arg0 + 0x20, func_001F1330());
    ((struct func_001DCA28_arg0 *)arg0)->unk30 = arg2;
}
