#include "types.h"
#include "gt4/mImport.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0030F740(s32, s32);                    /* extern */
s32 RefCounter__structor_0();                            /* extern */

extern char mImport__vtable[];
s32 mImport__structor_0(void *arg0, s32 arg1, s32 *arg2) {
    RefCounter__structor_0();
    ((struct mImport *)arg0)->unk4 = (s32)mImport__vtable;
    func_0030F740(arg0 + 8, arg1);
    ((struct mImport *)arg0)->unk18 = (s32) *arg2;
}
