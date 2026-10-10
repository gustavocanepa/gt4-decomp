#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005A48D8(void *, s32, s32);            /* extern */

struct func_003433E8_arg0 {
    char pad0[0x14];
    s8 unk14;
};

void func_003433E8(struct func_003433E8_arg0 *arg0) {
    func_005A48D8(arg0, 0, 0x20);
    arg0->unk14 = 1;
}
