#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 FlareClass__setReflectionFlareParameter(s32, f32, f32, f32, f32, f32, f32, f32); /* extern */

struct func_00398918_arg0 {
    char pad0[0xE60];
    f32 unkE60;
    f32 unkE64;
    f32 unkE68;
    f32 unkE6C;
    f32 unkE70;
    f32 unkE74;
    f32 unkE78;
    f32 unkE7C;
};

void CourseEnvPtr__setReflectionFlareParameter(void *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = ((struct func_00398918_arg0 *)arg0)->unkE6C;
    FlareClass__setReflectionFlareParameter(arg1, ((struct func_00398918_arg0 *)arg0)->unkE60 * temp_f0, ((struct func_00398918_arg0 *)arg0)->unkE64 * temp_f0, ((struct func_00398918_arg0 *)arg0)->unkE68 * temp_f0, ((struct func_00398918_arg0 *)arg0)->unkE70, ((struct func_00398918_arg0 *)arg0)->unkE74, ((struct func_00398918_arg0 *)arg0)->unkE78, ((struct func_00398918_arg0 *)arg0)->unkE7C);
}
