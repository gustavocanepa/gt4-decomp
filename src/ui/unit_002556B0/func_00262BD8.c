#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 MfloatReader__structor_5(s32);                             /* extern */

struct func_00262BD8_arg0 {
    char pad0[0x38];
    f32 unk38;
};

void func_00262BD8(struct func_00262BD8_arg0 *arg0, s32 arg1) {
    arg0->unk38 = MfloatReader__structor_5(arg1);
}
