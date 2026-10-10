#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00538C68(void *);                      /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_0052D4E0_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x4];
    s32 unk10;
    s32 unk14;
};

void func_0052D4E0(void *arg0) {
    if ((arg0 != NULL) && (((struct func_0052D4E0_arg0 *)arg0)->unk10 != 0) && (((struct func_0052D4E0_arg0 *)arg0)->unk14 != 0) && (((struct func_0052D4E0_arg0 *)arg0)->unk8 != 0)) {
        func_00538C68(arg0 + 0x10);
        func_005A48D8(arg0, 0, 0x18);
    }
}
