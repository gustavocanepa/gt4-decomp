#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00434E20(s32);                         /* extern */

struct func_004358C8_arg0 {
    char pad0[0x81C8];
    s32 unk81C8;
};

void func_004358C8(void *arg0, s32 arg1, s32 arg2) {
    func_00434E20(arg0 + (arg1 << 5) + 8);
    if (arg2 != 0) {
        ((struct func_004358C8_arg0 *)arg0)->unk81C8 = arg1;
    }
}
