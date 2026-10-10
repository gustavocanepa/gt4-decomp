#include "types.h"
#include "gt4/mEyetoyFace.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001B9D18(s32);                         /* extern */
s32 func_001BEEF8(void *);                      /* extern */
s32 mWidget__structor_0();                            /* extern */

extern char mEyetoyFace__vtable[];
void mEyetoyFace__structor_0(void *arg0) {
    mWidget__structor_0();
    ((struct mEyetoyFace *)arg0)->unk4 = (s32)mEyetoyFace__vtable;
    func_001B9D18(arg0 + 0xA0);
    func_001BEEF8(arg0 + 0xA4);
    ((struct mEyetoyFace *)arg0)->unkA8 = 0;
}
