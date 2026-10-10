#include "types.h"
#include "gt4/mModuleDefine.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0030F740(s32, s32);                    /* extern */
s32 RefCounter__structor_0();                            /* extern */

extern char mModuleDefine__vtable[];
void mModuleDefine__structor_0(void *arg0, s32 arg1) {
    RefCounter__structor_0();
    ((struct mModuleDefine *)arg0)->unk4 = (s32)mModuleDefine__vtable;
    func_0030F740(arg0 + 8, arg1);
    ((struct mModuleDefine *)arg0)->unk18 = 0;
}
