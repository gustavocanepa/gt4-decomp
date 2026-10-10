#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00238F80(s32, f32);                    /* extern */
s32 func_00238F98(s32, f32);                    /* extern */

struct func_00194148_arg0 {
    char pad0[0xD8];
    s32 unkD8;
};

void func_00194148(void *arg0, f32 fparg0, f32 fparg1) {
    func_00238F98(((struct func_00194148_arg0 *)arg0)->unkD8, fparg1);
    func_00238F80(((struct func_00194148_arg0 *)arg0)->unkD8, fparg0);
}
