#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00105378();                            /* extern */
s32 func_00105528(void *);                      /* extern */

struct func_00105338_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x28];
    s32 unk30;
};

void func_00105338(struct func_00105338_arg0 *arg0, s32 arg1, s32 arg2) {
    func_00105378();
    arg0->unk4 = arg2;
    arg0->unk30 = 0;
    func_00105528(arg0);
}
