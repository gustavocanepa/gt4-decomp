#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0054EB20(void *, s32, s32, s32, s32);  /* extern */
s32 func_0057F238(s32, void *);                     /* extern */

struct func_0054EBE0_arg0 {
    char pad0[0x190];
    s32 unk190;
};

void func_0054EBE0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_s1;
    s32 var_s2;

    var_s1 = arg1;
    var_s2 = arg2;
    if (((struct func_0054EBE0_arg0 *)arg0)->unk190 != 0) {
        if (func_0057F238(var_s1, arg0 + 0x90) == 0) {
            var_s1 = 0;
            var_s2 = 0;
        }
    }
    func_0054EB20(arg0, var_s1, var_s2, arg3, arg4);
}
