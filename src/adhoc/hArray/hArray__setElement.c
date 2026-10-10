#include "types.h"
#include "gt4/hArray.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002EF650(void *, u32);                 /* extern */
u32 hArray__size();                                /* extern */
s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

void hArray__setElement(struct hArray *arg0, u32 arg1, s32 *arg2) {
    s32 *temp_s1;
    s32 temp_s0;
    s32 temp_v0;

    if (arg1 >= hArray__size()) {
        func_002EF650(arg0, arg1);
    }
    temp_s1 = arg0->unk14 + (arg1 * 4);
    if (temp_s1 != arg2) {
        temp_s0 = *arg2;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0 = *temp_s1;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        *temp_s1 = temp_s0;
    }
}
