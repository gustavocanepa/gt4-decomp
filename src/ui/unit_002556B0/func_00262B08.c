#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 MfloatReader__structor_5(s32);                             /* extern */

struct func_00262B08_arg0 {
    char pad0[0x3C];
    f32 unk3C;
};

void func_00262B08(struct func_00262B08_arg0 *arg0, s32 arg1) {
    arg0->unk3C = MfloatReader__structor_5(arg1);
}
