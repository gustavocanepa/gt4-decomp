#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 MfloatReader__structor_5(s32);                             /* extern */

struct func_002626D8_arg0 {
    char pad0[0x88];
    f32 unk88;
};

void func_002626D8(struct func_002626D8_arg0 *arg0, s32 arg1) {
    arg0->unk88 = MfloatReader__structor_5(arg1);
}
