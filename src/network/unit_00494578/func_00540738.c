#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0053F300(s32, void *, s32);                /* extern */

struct func_00540738_arg1 {
    char pad0[0x20C];
    s32 unk20C;
};

void func_00540738(s32 arg0, void *arg1) {
    if ((((struct func_00540738_arg1 *)arg1)->unk20C == 0) && (func_0053F300(arg1 + 0x108, arg1 + 0x208, arg0) == 0)) {
        ((struct func_00540738_arg1 *)arg1)->unk20C = 1;
    }
}
