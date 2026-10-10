#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00345B28(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00679958[];
struct func_003467A0_arg0 {
    char pad0[0x6C];
    s32 unk6C;
};

void func_003467A0(void *arg0, s32 arg1) {
    ((struct func_003467A0_arg0 *)arg0)->unk6C = (s32)D_00679958;
    func_00345B28(arg0 + 8, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
