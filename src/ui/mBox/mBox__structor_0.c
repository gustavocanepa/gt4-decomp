#include "types.h"
#include "gt4/mBox.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 mComposite__structor_0();                            /* extern */
s32 func_00206858(void *, s32);             /* extern */

extern char mBox__vtable[];
void mBox__structor_0(struct mBox *arg0) {
    mComposite__structor_0();
    arg0->unkB0 = 0;
    arg0->unkB4 = 0;
    arg0->unk4 = (s32)mBox__vtable;
    arg0->unkB8 = 0;
    arg0->unkBC = 0;
    func_00206858(arg0, 1);
}
