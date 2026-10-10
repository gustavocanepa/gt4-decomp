#include "types.h"
#include "gt4/RaceFreeRun.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RacePS2Base__update();                            /* extern */
s32 RaceCarSound__setNarration(s32);                     /* extern */
f32 func_003C0FB0(s32);                             /* extern */
s32 func_00460600(f32);                         /* extern */
s32 BGM__narrationEnable();                                /* extern */

s32 RaceFreeRun__update(struct RaceFreeRun *arg0) {
    f32 temp_f0;

    RacePS2Base__update();
    if (BGM__narrationEnable() != 0) {
        if ((arg0->unk24698 != 0) && (arg0->unk246A4 == 0)) {
            RaceCarSound__setNarration(1);
        } else {
            RaceCarSound__setNarration(0);
        }
        temp_f0 = func_003C0FB0(arg0->unk6C);
        if (temp_f0 < 1.0f) {
            func_00460600(temp_f0);
        }
    }
}
