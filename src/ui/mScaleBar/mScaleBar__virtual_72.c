#include "types.h"
#include "gt4/mScaleBar.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00238A10(void *, s32);                 /* extern */
s32 func_00238A70(void *, s32);                             /* extern */
s32 func_00238B28(void *, s32);                     /* extern */
s32 func_00238FF0(void *, f32);                 /* extern */
s32 mSceneViewFace__virtual_72(void *, s32, void *);         /* extern */

struct mScaleBar__virtual_72_arg2 {
    char pad0[0x20];
    s32 unk20;
};
void mScaleBar__virtual_72(struct mScaleBar *arg0, s32 arg1, struct mScaleBar__virtual_72_arg2 *arg2) {
    s32 temp_s0;

    temp_s0 = arg2->unk20;
    if ((func_00238A70(arg0, temp_s0) != 0) || (func_00238B28(arg0, temp_s0) != 0)) {
        func_00238FF0(arg0, arg0->unkC4);
        func_00238A10(arg0, arg1);
    }
    mSceneViewFace__virtual_72(arg0, arg1, arg2);
}
