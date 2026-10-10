#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_0064B710[];
struct func_005201E0_temp_v0 {
    char pad0[0x3C];
    s32 (*unk3C)(s32, s32, s32, s32);
};

s32 func_005201E0(s32 arg0) {
    struct func_005201E0_temp_v0 *temp_v0;

    temp_v0 = *(void **)D_0064B710;
    if (temp_v0 != NULL) {
        return temp_v0->unk3C(arg0 & 0x7FFFFFFF, 0xFFFF, 0, 0);
    }
    return 0;
}
