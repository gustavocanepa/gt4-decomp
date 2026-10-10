#include "types.h"
#include "gt4/mKeyboardBox.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char mKeyboardBox__vtable[];
s32 mComposite__structor_0(void *);
void func_002A5D90(void *, s32 *);
void mKeyboardBox__structor_0(void *arg0) {
    s32 sp[4];
    mComposite__structor_0(arg0);
    ((struct mKeyboardBox *)arg0)->unk4 = (s32)mKeyboardBox__vtable;
    sp[0] = 0;
    func_002A5D90((s8 *)arg0 + 0xB0, sp);
}
