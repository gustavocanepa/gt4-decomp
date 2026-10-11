#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AF0A0(void *, s32);             /* extern */
s32 func_004AFCE8(s32, s32);                /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688F28[];
struct func_004AF5D8_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_004AF5D8(void *arg0, s32 arg1) {
    ((struct func_004AF5D8_arg0 *)arg0)->unkA8 = (s32)D_00688F28;
    func_004AFCE8(arg0 + 0xB0, 2);
    func_004AF0A0(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
