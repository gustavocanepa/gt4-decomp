#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 MintReader__structor_6(s32);                             /* extern */

struct func_00262AC0_arg0 {
    char pad0[0x98];
    s32 unk98;
};

void func_00262AC0(struct func_00262AC0_arg0 *arg0, s32 arg1) {
    arg0->unk98 = (s32) ((arg0->unk98 & ~0xF0) | ((MintReader__structor_6(arg1) & 0xF) * 0x10));
}
