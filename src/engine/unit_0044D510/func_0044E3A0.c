#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0044E3A0_arg0 {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
};

void func_0044E3A0(struct func_0044E3A0_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk10 = fparg0;
    arg0->unk14 = fparg1;
}
