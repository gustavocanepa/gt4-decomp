#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00435958(s32, s32);                    /* extern */

struct func_00601400_arg0 {
    s32 unk0;
    s32 unk4;
};

void *func_00601400(struct func_00601400_arg0 *arg0, s32 arg1) {
    arg0->unk4 = func_00435958(arg1, -1);
    arg0->unk0 = arg1;
    return arg0;
}
