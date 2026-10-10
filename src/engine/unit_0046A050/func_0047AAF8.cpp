#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00477460(s32);                             /* extern */
s32 func_0047DA90(s32, f32);                    /* extern */

void func_0047AAF8(s32 arg0, s32 arg1) {
    func_0047DA90(arg0, func_00477460(arg1));
}
