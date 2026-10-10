#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0047DBC8(s32);                             /* extern */

struct func_0047AE68_arg0 {
    s32 unk0;
    f32 unk4;
};

void *func_0047AE68(struct func_0047AE68_arg0 *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = func_0047DBC8(arg1) * 100.0f;
    arg0->unk0 = 6;
    arg0->unk4 = temp_f0;
    return arg0;
}
