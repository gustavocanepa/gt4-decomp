#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00477460(s32);                             /* extern */
s32 func_0047DBB0(s32, f32);                    /* extern */

void func_0047ADA0(s32 arg0, s32 arg1) {
    func_0047DBB0(arg0, func_00477460(arg1) * 0x1.47ae140000000p-7f);
}
