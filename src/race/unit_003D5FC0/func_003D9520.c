#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003D95A0();                            /* extern */
s32 func_003D9E88(void *);                      /* extern */
s32 func_003D9F20(void *);                      /* extern */
s32 func_00426AF8(s32);                             /* extern */

struct func_003D9520_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
};

s32 func_003D9520(struct func_003D9520_arg0 *arg0, s32 arg1) {
    if ((arg0->unk1C == 0) || (arg0->unk20 != 0)) {
        func_003D95A0();
    }
    if (func_00426AF8(arg1) & 0x20) {
        func_003D9E88(arg0);
    }
    if (func_00426AF8(arg1) & 0x40) {
        func_003D9F20(arg0);
    }
}
