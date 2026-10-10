#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00578CF0(s32, s32);                    /* extern */
s32 func_0058C9D0();                                /* extern */
s32 func_0058C9F8();                                /* extern */

struct func_001C50A8_arg0 {
    char pad0[0x25C];
    s32 unk25C;
    s32 unk260;
};

void func_001C50A8(struct func_001C50A8_arg0 *arg0) {
    if (arg0->unk25C == 0) {
        arg0->unk25C = func_00578CF0(0x80, ((func_0058C9D0() + 0x7F) & ~0x7F) + 0x80);
    }
    if (arg0->unk260 == 0) {
        arg0->unk260 = func_00578CF0(0x80, ((func_0058C9F8() + 0x7F) & ~0x7F) + 0x80);
    }
}
