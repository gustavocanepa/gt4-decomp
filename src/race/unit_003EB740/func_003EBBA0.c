#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00427820(void *);                      /* extern */
s32 func_00427830(void *, s32, s32);        /* extern */
s32 func_0042A0D0(void *, s32);                     /* extern */

struct func_003EBBA0_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_003EBBA0(struct func_003EBBA0_arg0 *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10];
    if ((arg1 != 0) && (arg2 != 0)) {
        arg0->unk4 = 0;
        func_00427820(sp);
        func_00427830(sp, 0, arg1);
        arg0->unk0 = func_0042A0D0(sp, arg2);
    }
}
