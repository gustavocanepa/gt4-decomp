#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0044A760();                            /* extern */
s32 func_00574DA8(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688368[];
struct func_0044A670_arg0 {
    char pad0[0x40];
    s32 unk40;
};

void func_0044A670(void *arg0, s32 arg1) {
    ((struct func_0044A670_arg0 *)arg0)->unk40 = (s32)D_00688368;
    func_0044A760();
    func_00574DA8(arg0 + 0x10, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
