#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 MfloatReader__structor_5(s32);                             /* extern */

struct func_00262B38_arg0 {
    char pad0[0x34];
    f32 unk34;
};

void func_00262B38(struct func_00262B38_arg0 *arg0, s32 arg1) {
    arg0->unk34 = MfloatReader__structor_5(arg1);
}
