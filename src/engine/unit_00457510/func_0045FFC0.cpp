#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00462868();                                /* extern */
f32 func_00462DB0(s32, s32);                    /* extern */
s32 func_00547A88(f32);                         /* extern */

void func_0045FFC0(f32 fparg0) {
    func_00547A88(fparg0 * func_00462DB0(func_00462868(), 0));
}
