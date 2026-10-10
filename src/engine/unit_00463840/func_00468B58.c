#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00467C58(s32);                             /* extern */
s32 func_00467D90(s32);                             /* extern */
s32 func_00467F60(s32);                             /* extern */
s32 func_004680D8(s32);                         /* extern */
s32 func_004683A8();                                /* extern */

void func_00468B58(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 temp_v0;

    temp_v0 = func_004683A8();
    *arg0 = func_00467C58(temp_v0);
    *arg1 = func_00467D90(temp_v0);
    *arg2 = func_00467F60(temp_v0);
    func_004680D8(temp_v0);
}
