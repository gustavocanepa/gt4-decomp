#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00480FA0(s32, s32);                    /* extern */
s32 func_005A5600();                                /* extern */

f32 func_0047C150(s32 arg0, s32 arg1) {
    func_00480FA0(arg1, arg0);
    return (f32) func_005A5600() / 0x1.fffffe0000000p+30f;
}
