#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0044ACD8(void *, void *);              /* extern */
s32 func_005A48D8(void *, s32, s32);        /* extern */

struct func_0044AEF0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

void func_0044AEF0(void *arg0) {
    s32 temp_v0;

    temp_v0 = ((struct func_0044AEF0_arg0 *)arg0)->unk1C;
    if (temp_v0 != 0) {
        func_005A48D8(arg0 + temp_v0 + 0x14, 0, 8 - temp_v0);
        func_0044ACD8(arg0, arg0 + 0x14);
        ((struct func_0044AEF0_arg0 *)arg0)->unk1C = 0;
    }
}
