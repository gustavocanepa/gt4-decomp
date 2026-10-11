#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_006923C8[];
void mPhotoRenderFace__structor_0(s32);
void func_00255088(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_00197B80(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x100, 4, D_006923C8);
    mPhotoRenderFace__structor_0(temp_v0);
    sp[0] = temp_v0;
    func_00255088(arg0, sp);
}
