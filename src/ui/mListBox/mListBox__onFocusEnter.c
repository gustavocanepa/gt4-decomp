#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 mWidget__onFocusEnter();                            /* extern */
void *func_0028EA18(s32);                           /* extern */

struct mListBox__virtual_80_temp_v0 {
    char pad0[0x14C];
    s32 unk14C;
};

s32 mListBox__onFocusEnter(s32 arg0, s32 arg1, s32 arg2) {
    struct mListBox__virtual_80_temp_v0 *temp_v0;

    mWidget__onFocusEnter();
    temp_v0 = func_0028EA18(arg2);
    if (temp_v0 == arg0) {
        temp_v0->unk14C = 1;
    }
    return 1;
}
