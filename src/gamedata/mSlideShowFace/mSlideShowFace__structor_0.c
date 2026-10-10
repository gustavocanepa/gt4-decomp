#include "types.h"
#include "gt4/mSlideShowFace.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001C6AD0(void *);                      /* extern */
s32 func_001C7208(void *);                      /* extern */
s32 mWidget__structor_0();                            /* extern */

extern char mSlideShowFace__vtable[];
void mSlideShowFace__structor_0(void *arg0) {
    mWidget__structor_0();
    ((struct mSlideShowFace *)arg0)->unkA0 = 0;
    ((struct mSlideShowFace *)arg0)->unkA4 = 0;
    ((struct mSlideShowFace *)arg0)->unk4 = (s32)mSlideShowFace__vtable;
    ((struct mSlideShowFace *)arg0)->unkA8 = 0;
    ((struct mSlideShowFace *)arg0)->unkAC = 0;
    func_001C6AD0(arg0 + 0xBC);
    func_001C7208(arg0 + 0x1E9C);
    ((struct mSlideShowFace *)arg0)->unk1F50 = 0;
}
