#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

void * func_00359538(void *);
s32 func_00344E48(void *, u8, f32);             /* extern */

void func_0035A370(void *arg0, s32 arg1, f32 fparg0) {
    func_00344E48(arg0, M2C_FIELD((func_00359538(arg0) + arg1), u8 *, 0xC), fparg0);
}
