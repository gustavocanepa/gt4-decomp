#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 SystemSoundGetOutputMode(void);
f32 SystemSoundGetOutputModeVolume(s32, s32);
extern f32 D_006213D8;
extern f32 RaceCarSound__visual_volume_;
extern f32 D_0088F2D0;
f32 RaceCarSound__getMasterVolume(void) {
    f32 r = SystemSoundGetOutputModeVolume(SystemSoundGetOutputMode(), 2);
    return D_006213D8 * RaceCarSound__visual_volume_ * D_0088F2D0 * r;
}
