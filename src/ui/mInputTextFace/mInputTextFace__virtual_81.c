#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002321D0(s32);                         /* extern */
s32 mSceneViewFace__virtual_81();                            /* extern */
s32 func_0028EA18(s32);                             /* extern */

s32 mInputTextFace__virtual_81(s32 arg0, s32 arg1, s32 arg2) {
    mSceneViewFace__virtual_81();
    if (func_0028EA18(arg2) == arg0) {
        func_002321D0(arg1);
    }
    return 0;
}
