#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003A1E10(s32);                             /* extern */

struct func_003AC340_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    char pad30[0x3C];
    s32 unk6C;
};

void RaceMTRMeter__init_texset(struct func_003AC340_arg0 *arg0) {
    if (arg0->unk18 == 0) {
        arg0->unk18 = func_003A1E10(*(s32 *)(0x621520 + (arg0->unk6C * 4)));
        arg0->unk1C = func_003A1E10((s32)"mtr_accel");
        arg0->unk20 = func_003A1E10((s32)"mtr_brake");
        arg0->unk24 = func_003A1E10((s32)"mtr_asm");
        arg0->unk28 = func_003A1E10((s32)"mtr_tcs");
        arg0->unk2C = func_003A1E10((s32)"mtr_grip");
    }
}
