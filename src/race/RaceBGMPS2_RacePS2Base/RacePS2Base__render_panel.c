#include "types.h"
#include "gt4/RacePS2Base.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003425E0(s32, s32, f32);               /* extern */

s32 RacePS2Base__render_panel(struct RacePS2Base *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = arg0->unkCF4C;
    if (temp_f0 < 1.0f) {
        func_003425E0(arg1, arg0->unkCF60, 1.0f - (1.0f - (temp_f0 * temp_f0 * temp_f0)));
    }
}
