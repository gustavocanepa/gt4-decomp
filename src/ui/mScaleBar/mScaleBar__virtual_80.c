#include "types.h"
#include "gt4/mScaleBar.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00238A10(void *, s32);                 /* extern */
s32 func_00238FC0(void *, f32);                 /* extern */
s32 func_00238FF0(void *, f32);                 /* extern */
s32 mWidget__onFocusEnter();                            /* extern */

s32 mScaleBar__virtual_80(struct mScaleBar *arg0, s32 arg1) {
    mWidget__onFocusEnter();
    func_00238FC0(arg0, arg0->unkC4);
    func_00238FF0(arg0, arg0->unkC4);
    func_00238A10(arg0, arg1);
    return 1;
}
