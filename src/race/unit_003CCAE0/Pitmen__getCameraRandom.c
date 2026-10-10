#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005792E8(void *, s32);                 /* extern */
s32 func_00579330(void *);                          /* extern */

struct func_003CCBD0_arg0 {
    char pad0[0x96D4];
    s32 unk96D4;
};

s32 Pitmen__getCameraRandom(struct func_003CCBD0_arg0 *arg0) {
    s8 sp[0x10];
    s32 temp_s0;

    temp_s0 = arg0->unk96D4;
    func_005792E8(sp, temp_s0);
    arg0->unk96D4 = func_00579330(sp);
    return temp_s0;
}
