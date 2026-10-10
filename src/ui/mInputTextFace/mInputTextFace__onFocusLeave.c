#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 mRenderContext__closeOSKeyboard(s32);                         /* extern */
s32 mWidget__onFocusLeave();                            /* extern */
s32 func_0028EA18(s32);                             /* extern */

s32 mInputTextFace__onFocusLeave(s32 arg0, s32 arg1, s32 arg2) {
    mWidget__onFocusLeave();
    if (func_0028EA18(arg2) == arg0) {
        mRenderContext__closeOSKeyboard(arg1);
    }
    return 0;
}
