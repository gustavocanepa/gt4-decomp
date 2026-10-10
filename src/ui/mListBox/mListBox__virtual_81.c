#include "types.h"
#include "gt4/mListBox.h"
void *memcpy(void *, const void *, unsigned int);

s32 mSceneViewFace__virtual_81();                            /* extern */
s32 func_002B3AF8(void *, s32);                 /* extern */
s32 func_002B5270(void *, s32);                 /* extern */

s32 mListBox__virtual_81(struct mListBox *arg0, s32 arg1) {
    s32 temp_s1;

    mSceneViewFace__virtual_81();
    temp_s1 = arg0->unk12C;
    func_002B5270(arg0, arg1);
    if (temp_s1 >= 0) {
        func_002B3AF8(arg0, temp_s1);
    }
    func_002B3AF8(arg0, arg0->unk124);
    return 1;
}
