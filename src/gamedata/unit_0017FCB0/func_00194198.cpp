#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00238FF0(s32, f32);                    /* extern */
s32 func_00239020(s32);                         /* extern */

struct func_00194198_arg0 {
    char pad0[0xD8];
    s32 unkD8;
};

void func_00194198(void *arg0, f32 fparg0) {
    func_00239020(((struct func_00194198_arg0 *)arg0)->unkD8);
    func_00238FF0(((struct func_00194198_arg0 *)arg0)->unkD8, fparg0);
}
