#include "types.h"
#include "gt4/mColorObject.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002030C0(s32, s32);                    /* extern */
s32 hObject__structor_0();                            /* extern */

extern char mColorObject__vtable[];
void mColorObject__structor_1(void *arg0, s32 arg1) {
    hObject__structor_0();
    ((struct mColorObject *)arg0)->unk4_s32 = (s32)mColorObject__vtable;
    func_002030C0(arg0 + 0x10, arg1);
}
