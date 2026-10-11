#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 mListBox__get_width();                                /* extern */
f32 mListBox__getTotal(s32);                             /* extern */

f32 mListBox__getVolumeRatio(s32 arg0) {
    f32 temp_f20;

    temp_f20 = mListBox__get_width();
    return temp_f20 / mListBox__getTotal(arg0);
}
