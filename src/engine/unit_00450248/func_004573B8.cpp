#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00457300(s32, s32, s32);           /* extern */
s32 ModelSet2__evalHostMethod();                            /* extern */

void func_004573B8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        ModelSet2__evalHostMethod();
        func_00457300(arg0, 1, arg1);
    }
}
