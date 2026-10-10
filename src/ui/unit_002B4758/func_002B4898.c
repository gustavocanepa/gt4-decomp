#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

struct func_002B4898_arg0 {
    char pad0[0x118];
    s32 unk118;
};

void func_002B4898(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if ((arg0 + 0x118) != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0 = ((struct func_002B4898_arg0 *)arg0)->unk118;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        ((struct func_002B4898_arg0 *)arg0)->unk118 = temp_s0;
    }
}
