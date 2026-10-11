/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0053F398(void *, s32);                     /* extern */
s32 func_00594470(s32, s32, s32);           /* extern */
s32 func_005A6AB0(s32, s8 *, s32);              /* extern */

struct func_00540788_arg2 {
    char pad0[0x208];
    s32 unk208;
    s32 unk20C;
    s32 unk210;
};

void func_00540788(s8 *arg0, s32 arg1, void *arg2) {
    s32 temp_s2;

    temp_s2 = ((struct func_00540788_arg2 *)arg2)->unk210;
    if ((((struct func_00540788_arg2 *)arg2)->unk20C == 0) && (arg1 != 0) && (*arg0 != 0x20) && (func_00594470(func_0053F398(arg2 + 0x108, ((struct func_00540788_arg2 *)arg2)->unk208), (s32)"return", 0x100) == 0)) {
        func_005A6AB0(temp_s2, arg0, arg1);
    }
}
