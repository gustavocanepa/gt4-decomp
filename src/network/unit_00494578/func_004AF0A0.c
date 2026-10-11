#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00574DA8(void *, s32);                     /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688ED0[];
struct func_004AF0A0_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_004AF0A0(struct func_004AF0A0_arg0 *arg0, s32 arg1) {
    arg0->unkA8 = (s32)D_00688ED0;
    func_00574DA8(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
