#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 MboolReader__structor_8(void *);                          /* extern */
s32 func_00265D10(s32, s32);                    /* extern */

struct func_00262420_arg1 {
    char pad0[0x24];
    s32 unk24;
};

void func_00262420(s32 arg0, struct func_00262420_arg1 *arg1) {
    s32 temp_v0;

    temp_v0 = MboolReader__structor_8(arg1);
    func_00265D10(arg0, temp_v0);
    if (temp_v0 != 0) {
        arg1->unk24 = 1;
    }
}
