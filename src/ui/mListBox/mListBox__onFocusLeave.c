#include "types.h"
#include "gt4/mListBox.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 mWidget__onFocusLeave();                            /* extern */
s32 mListBox__setFocusIndex(void *, s32);                 /* extern */
s32 mListBox__leaveDragMode(void *, s32);                 /* extern */

s32 mListBox__onFocusLeave(struct mListBox *arg0, s32 arg1) {
    s32 temp_s1;

    mWidget__onFocusLeave();
    temp_s1 = arg0->unk12C;
    mListBox__leaveDragMode(arg0, arg1);
    if (temp_s1 >= 0) {
        mListBox__setFocusIndex(arg0, temp_s1);
    }
    mListBox__setFocusIndex(arg0, arg0->unk124);
    return 1;
}
