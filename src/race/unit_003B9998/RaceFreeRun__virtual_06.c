#include "types.h"
#include "gt4/RaceFreeRun.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RacePS2Base__virtual_06();                            /* extern */
s32 func_00391E80(s32);                     /* extern */
f32 func_003C0FB0(s32);                             /* extern */
s32 func_00460600(f32);                         /* extern */
s32 func_00460648();                                /* extern */

s32 RaceFreeRun__virtual_06(struct RaceFreeRun *arg0) {
    f32 temp_f0;

    RacePS2Base__virtual_06();
    if (func_00460648() != 0) {
        if ((arg0->unk24698 != 0) && (arg0->unk246A4 == 0)) {
            func_00391E80(1);
        } else {
            func_00391E80(0);
        }
        temp_f0 = func_003C0FB0(arg0->unk6C);
        if (temp_f0 < 1.0f) {
            func_00460600(temp_f0);
        }
    }
}
