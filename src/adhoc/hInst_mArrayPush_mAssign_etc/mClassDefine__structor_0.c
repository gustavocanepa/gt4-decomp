#include "types.h"
#include "gt4/mClassDefine.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0030F740(s32, s32);                    /* extern */
s32 RefCounter__structor_0();                            /* extern */

extern char mClassDefine__vtable[];
void mClassDefine__structor_0(void *arg0, s32 *arg1, s32 arg2) {
    RefCounter__structor_0();
    ((struct mClassDefine *)arg0)->unk4 = (s32)mClassDefine__vtable;
    ((struct mClassDefine *)arg0)->unk8 = (s32) *arg1;
    func_0030F740(arg0 + 0xC, arg2);
    ((struct mClassDefine *)arg0)->unk1C = 0;
}
