#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_0064B710[];
struct func_0050EED0_temp_v0 {
    char pad0[0x68];
    s32 (*unk68)(s32, s32, s32);
};

struct func_0050EED0_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_0050EED0(void *arg0) {
    struct func_0050EED0_temp_v0 *temp_v0;

    temp_v0 = *(void **)D_0064B710;
    if (temp_v0 != NULL) {
        temp_v0->unk68(((struct func_0050EED0_arg0 *)arg0)->unk0, ((struct func_0050EED0_arg0 *)arg0)->unk4, arg0 + 8);
    }
    return 0;
}
