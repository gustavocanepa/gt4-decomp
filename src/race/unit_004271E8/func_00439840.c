#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005A48D8(s32, s32, s32);       /* extern */

struct func_00439840_arg0 {
    char pad0[0x4];
    s8 unk4;
    char pad5[0x3F];
    s16 unk44;
};

void func_00439840(void *arg0) {
    func_005A48D8(arg0 + 4, 0, 0x50);
    ((struct func_00439840_arg0 *)arg0)->unk4 = 0;
    ((struct func_00439840_arg0 *)arg0)->unk44 = 0;
}
