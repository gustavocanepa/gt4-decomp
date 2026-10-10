#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 Pitmen__isPitCameraPeriod();
struct func_003D2928_temp_s0 {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
};

s32 Pitmen__isHandCameraPeriod(s32 arg0, s32 arg1) {
    struct func_003D2928_temp_s0 *temp_s0;
    temp_s0 = (void *)(arg0 + 4);
    if ((temp_s0->unk30 == 0) || (temp_s0->unk34 == 0)) {
        return 0;
    }
    if (Pitmen__isPitCameraPeriod() == 0) return 0;
    if (M2C_FIELD(((arg1 * 4) + (s8 *)temp_s0), s32 *, 0xB0) < 8) return 0;
    return 1;
}
