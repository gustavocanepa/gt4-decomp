#include "types.h"
#include "gt4/mOptionMenu.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00208428(s32);                             /* extern */
s32 func_00265E50(s32, s32);                /* extern */
s32 func_002C8198(void *, s32);                 /* extern */
s32 func_00309378(void *, s32);             /* extern */
s32 func_0030BB18(void *);                      /* extern */
s32 func_0057CD90(void *, s32, s32);        /* extern */

void mOptionMenu__virtual_103(void *arg0, s32 arg1) {
    s8 sp[0x10];
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;

    func_0030BB18(sp);
    temp_v1 = ((struct mOptionMenu *)arg0)->unkC0;
    if (temp_v1 != 0) {
        func_00265E50(temp_v1, 0);
    }
    temp_a0 = ((struct mOptionMenu *)arg0)->unkC4;
    if (temp_a0 != 0) {
        temp_v0 = func_00208428(temp_a0);
        func_0057CD90(arg0 + 0xD8, 0, temp_v0);
        if (temp_v0 > 0) {
            func_002C8198(arg0, arg1);
        }
    }
    ((struct mOptionMenu *)arg0)->unkFC = 0;
    func_00309378(sp, 2);
}
