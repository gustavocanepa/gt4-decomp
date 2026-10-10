#include "types.h"
#include "gt4/mSelectBar.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00206868(void *);                          /* extern */
f32 func_0025B370(s32);                             /* extern */
f32 func_0025B3D0(s32);                             /* extern */
s32 mSceneViewFace__virtual_63();                            /* extern */

void mSelectBar__virtual_63(struct mSelectBar *arg0) {
    s32 temp_v0;

    mSceneViewFace__virtual_63();
    temp_v0 = func_00206868(arg0);
    if (temp_v0 != 0) {
        arg0->unkE4 = func_0025B370(temp_v0);
        arg0->unkE8 = func_0025B3D0(temp_v0);
    }
}
