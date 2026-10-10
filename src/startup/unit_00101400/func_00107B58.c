#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00107B98();                            /* extern */
s32 func_004AA558(s32);                             /* extern */

struct func_00107B58_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_00107B58(struct func_00107B58_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    func_00107B98();
    temp_v0 = func_004AA558(arg1);
    arg0->unk4 = arg1;
    arg0->unk0 = temp_v0;
}
