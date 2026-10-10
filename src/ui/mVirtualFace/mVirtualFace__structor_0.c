#include "types.h"
#include "gt4/mVirtualFace.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 mWidget__structor_0();                            /* extern */
s32 func_002FA120(s32);                         /* extern */
s32 func_0030BB18(void *);                      /* extern */

extern char mVirtualFace__vtable[];
void mVirtualFace__structor_0(void *arg0) {
    mWidget__structor_0();
    ((struct mVirtualFace *)arg0)->unk4 = (s32)mVirtualFace__vtable;
    func_002FA120(arg0 + 0xA0);
    func_0030BB18(arg0 + 0xA4);
}
