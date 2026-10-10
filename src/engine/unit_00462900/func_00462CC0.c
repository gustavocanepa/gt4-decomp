#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004629A0(void *, s32);                 /* extern */
s32 func_00462C50(void *, s32);                     /* extern */

struct func_00462CC0_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
};

void *func_00462CC0(struct func_00462CC0_arg0 *arg0, s32 arg1) {
    func_00462C50(arg0, 0);
    func_004629A0(arg0, arg1);
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    return arg0;
}
