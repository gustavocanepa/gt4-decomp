#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_002B4998(s32, s32);
s32 mListBox__get_total_item_count(s32);
s32 mListBox__getItemActive(s32 arg0, s32 arg1) {
    s32 r;
    if ((arg1 >= 0) && (arg1 < mListBox__get_total_item_count(arg0))) { s32 v = M2C_FIELD(func_002B4998(arg0, arg1), s32 *, 0x1C); r = (v >> 17) & 1; } else r = 0;
    return r;
}
