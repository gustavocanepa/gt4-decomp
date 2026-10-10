#include "types.h"
#include "gt4/mProject.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 mComposite__structor_0();                            /* extern */
s32 func_00485C40(s32);                         /* extern */

extern char mProject__vtable[];
void mProject__structor_0(void *arg0) {
    mComposite__structor_0();
    ((struct mProject *)arg0)->unk4 = (s32)mProject__vtable;
    func_00485C40(arg0 + 0xB0);
}
