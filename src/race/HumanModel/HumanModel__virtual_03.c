#include "types.h"
#include "gt4/HumanModel.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005FA890(s32, s32, s32);           /* extern */

extern char D_003B04B0[];
void HumanModel__virtual_03(struct HumanModel *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk6B0_s32;
    if (temp_v0 != 0) {
        func_005FA890(arg0->unk0, temp_v0, (s32)D_003B04B0);
        arg0->unk6B0_s32 = 0;
    }
}
