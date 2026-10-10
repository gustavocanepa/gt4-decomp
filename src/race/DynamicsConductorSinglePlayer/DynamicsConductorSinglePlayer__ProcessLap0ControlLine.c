#include "types.h"
#include "gt4/DynamicsConductorSinglePlayer.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00345228(void *);                      /* extern */
void *func_0034C190();                              /* extern */
s32 func_0035DF80(s32, s32, s32, s32); /* extern */
s32 func_003F37B8(void *);                      /* extern */

struct DynamicsConductorSinglePlayer__virtual_19_temp_v0 {
    char pad0[0x56B];
    u8 unk56B;
};

void DynamicsConductorSinglePlayer__ProcessLap0ControlLine(struct DynamicsConductorSinglePlayer *arg0, s32 arg1) {
    s32 temp_s1;
    struct DynamicsConductorSinglePlayer__virtual_19_temp_v0 *temp_v0;

    temp_s1 = arg0->unk0;
    temp_v0 = func_0034C190();
    if (temp_v0->unk56B == 1) {
        func_00345228(temp_v0);
        func_003F37B8(temp_v0);
        if (arg1 == 0) {
            func_0035DF80(temp_s1, 4, 0, 0);
        }
    }
    arg0->unkCBE4 = 0;
}
