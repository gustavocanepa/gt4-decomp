#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00499728(void *);                      /* extern */
s32 func_0049CC48(s32);                         /* extern */

struct func_00473750_arg1 {
    char pad0[0x18];
    s32 unk18;
};

void func_00473750(s32 arg0, void *arg1) {
    func_00499728(arg1);
    func_0049CC48(((struct func_00473750_arg1 *)arg1)->unk18);
}
