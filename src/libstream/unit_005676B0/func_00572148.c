#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00572060(void *, s32);             /* extern */
s32 func_00572470();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00689D28[];
struct func_00572148_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

void func_00572148(void *arg0, s32 arg1) {
    ((struct func_00572148_arg0 *)arg0)->unk7C = (s32)D_00689D28;
    func_00572470();
    func_00572060(arg0 + 0x4C, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
