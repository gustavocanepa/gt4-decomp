#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046CD48(void *, s32);                     /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00660D98[];
struct func_001C76C8_arg0 {
    char pad0[0x11D0];
    s32 unk11D0;
};

void func_001C76C8(struct func_001C76C8_arg0 *arg0, s32 arg1) {
    arg0->unk11D0 = (s32)D_00660D98;
    func_0046CD48(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
