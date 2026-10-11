#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00429BC0(s32);                             /* extern */

struct func_00429610_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_00429610(struct func_00429610_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 != 0) {
        return func_00429BC0(temp_v0);
    }
    return 0;
}
