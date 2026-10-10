#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 mRenderContextPS2__structor_0(s32, s32);                    /* extern */
s32 func_00326750(s32, s32, s32);       /* extern */

extern char D_00697970[];
s32 mUpdateContextPS2__virtual_62(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_00326750(0x1DAC, 4, (s32)D_00697970);
    mRenderContextPS2__structor_0(temp_v0, arg0);
    return temp_v0;
}
