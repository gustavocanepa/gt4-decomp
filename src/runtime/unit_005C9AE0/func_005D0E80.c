#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

void *func_00554478(s32, s32, s32);                 /* extern */

struct func_005D0E80_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};
struct func_005D0E80_temp_v0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

s32 func_005D0E80(struct func_005D0E80_arg0 *arg0) {
    struct func_005D0E80_temp_v0 *temp_v0;

    temp_v0 = func_00554478(arg0->unk4, arg0->unk8, arg0->unkC);
    if (temp_v0->unk0 == 0) {
        arg0->unk10 = (s32) temp_v0->unk8;
    }
    return temp_v0->unk0 == 0;
}
