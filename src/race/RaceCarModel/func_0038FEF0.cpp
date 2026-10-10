#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0038FFC8(s32, s32);                    /* extern */
s32 func_00575DA0(s32);                         /* extern */
s32 func_005C1628(void *);                      /* extern */

struct func_0038FEF0_arg1 {
    char pad0[0x94];
    s32 unk94;
};
struct func_0038FEF0_arg0 {
    char pad0[0x100];
    s32 unk100;
};

void func_0038FEF0(void *arg0, void *arg1) {
    s32 temp_s0;

    temp_s0 = ((struct func_0038FEF0_arg1 *)arg1)->unk94;
    func_0038FFC8(((struct func_0038FEF0_arg0 *)arg0)->unk100, temp_s0);
    func_00575DA0(temp_s0);
    func_005C1628(arg0);
}
