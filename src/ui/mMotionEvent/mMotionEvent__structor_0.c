#include "types.h"
#include "gt4/mMotionEvent.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 mWindowEvent__structor_0();                            /* extern */

extern char mMotionEvent__vtable[];
s32 mMotionEvent__structor_0(struct mMotionEvent *arg0, f32 fparg0, f32 fparg1) {
    mWindowEvent__structor_0();
    arg0->unk24 = fparg1;
    arg0->unk20 = fparg0;
    arg0->unk4 = (s32)mMotionEvent__vtable;
}
