#include "types.h"
#include "gt4/hStaticValue.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

void hStaticValue__virtual_09(void *arg0, s32 arg1, s32 *arg2) {
    s32 temp_s0;
    s32 temp_v0;

    if ((arg0 + 0xC) != arg2) {
        temp_s0 = *arg2;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0 = ((struct hStaticValue *)arg0)->unkC;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        ((struct hStaticValue *)arg0)->unkC = temp_s0;
    }
}
