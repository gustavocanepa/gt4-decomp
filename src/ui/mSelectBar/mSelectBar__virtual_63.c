#define GT4_DECLS
#include "gt4/mWidget.h"
#include "types.h"
#include "gt4/mSelectBar.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00206868(void *);                          /* extern */
s32 mSceneViewFace__virtual_63();                            /* extern */

void mSelectBar__virtual_63(struct mSelectBar *arg0) {
    s32 temp_v0;

    mSceneViewFace__virtual_63();
    temp_v0 = func_00206868(arg0);
    if (temp_v0 != 0) {
        arg0->unkE4 = mWidget__getWindowW(temp_v0);
        arg0->unkE8 = mWidget__getWindowH(temp_v0);
    }
}
