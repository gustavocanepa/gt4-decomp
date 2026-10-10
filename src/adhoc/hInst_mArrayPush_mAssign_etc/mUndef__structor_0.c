#include "types.h"
#include "gt4/mUndef.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0030F740(s32, s32);                    /* extern */
s32 RefCounter__structor_0();                            /* extern */

extern char mUndef__vtable[];
void mUndef__structor_0(void *arg0, s32 arg1) {
    RefCounter__structor_0();
    ((struct mUndef *)arg0)->unk4 = (s32)mUndef__vtable;
    func_0030F740(arg0 + 8, arg1);
}
