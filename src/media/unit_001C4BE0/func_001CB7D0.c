#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004CCFC0(s32, s32, s32, s32);              /* extern */

struct func_001CB7D0_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_001CB7D0(struct func_001CB7D0_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 >= 0) {
        return func_004CCFC0(arg0->unk0, temp_v0, arg1, arg2);
    }
    return -1;
}
