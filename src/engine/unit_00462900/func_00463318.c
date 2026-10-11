#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00462D30(f32, s32);                    /* extern */
s32 func_00576090(void *);                      /* extern */
s32 func_005760A8(void *, s32);             /* extern */
s32 func_00576100(void *);                      /* extern */
s32 func_00576140(void *);                      /* extern */

void func_00463318(s32 arg0, f32 fparg0) {
    s8 sp[0x10];
    func_00576090(sp);
    func_00576100(sp);
    func_00462D30(fparg0, arg0);
    func_00576140(sp);
    func_005760A8(sp, 2);
}
