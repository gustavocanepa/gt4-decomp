#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00503630();                            /* extern */
s32 func_005767C0(void *);                      /* extern */

struct func_004F0CD0_arg0 {
    char pad0[0x188];
    s32 unk188;
};

s32 func_004F0CD0(void *arg0, s32 arg1) {
    ((struct func_004F0CD0_arg0 *)arg0)->unk188 = arg1;
    func_00503630();
    func_005767C0(arg0 + 8);
    return 1;
}
