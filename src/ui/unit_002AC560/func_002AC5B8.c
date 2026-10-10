#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 mRenderContext__closePage(s32, s32);                    /* extern */
s32 mWidget__getRootWindow();                                /* extern */

s32 func_002AC5B8(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = mWidget__getRootWindow();
    if (temp_v0 != 0) {
        mRenderContext__closePage(arg1, temp_v0);
    }
    return 2;
}
