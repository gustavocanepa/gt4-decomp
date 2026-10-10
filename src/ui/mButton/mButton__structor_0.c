#include "types.h"
#include "gt4/mButton.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char mButton__vtable[];
s32 mComposite__structor_0(void *);
void func_00265F10(void *, s32);
void func_002F9B08(void *, s32 *);
void mButton__structor_0(void *arg0) {
    s32 sp[4];
    mComposite__structor_0(arg0);
    ((struct mButton *)arg0)->unk4 = (s32)mButton__vtable;
    sp[0] = 0;
    func_002F9B08((s8 *)arg0 + 0xB0, sp);
    func_00265F10(arg0, 1);
}
