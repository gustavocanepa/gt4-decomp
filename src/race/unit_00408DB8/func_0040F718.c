#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0040F670(f32);                             /* extern */
s32 func_004145C8(f32, f32);                    /* extern */

void func_0040F718(f32 fparg0, f32 fparg1) {
    func_004145C8(fparg0, func_0040F670(fparg1));
}
