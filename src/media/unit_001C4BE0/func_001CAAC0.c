#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_001CAAC0_p {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    char pad20[0x4];
    f32 unk24;
};

s32 func_001CAAC0(void **arg0) {
    void *p = *arg0;
    s32 flag = 1;
    if (!(((struct func_001CAAC0_p *)p)->unk24 < 1.0f)) flag = 0;
    if (flag) return ((struct func_001CAAC0_p *)p)->unk10 * ((struct func_001CAAC0_p *)p)->unk18;
    return ((struct func_001CAAC0_p *)p)->unk14 * ((struct func_001CAAC0_p *)p)->unk1C;
}
