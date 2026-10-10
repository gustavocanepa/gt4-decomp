#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00503868(s32);                             /* extern */

struct func_00504550_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_00504550(struct func_00504550_arg0 *arg0, s8 *arg1, s32 *arg2) {
    s32 temp_v0;

    *arg1 = 0;
    *arg2 = -1;
    if (arg0->unk0 != 0) {
        temp_v0 = arg0->unk4;
        if (temp_v0 != 0) {
            return func_00503868(temp_v0);
        }
    }
    return 0;
}
