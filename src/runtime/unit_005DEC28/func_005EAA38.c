/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00227128(s32 *, s32);              /* extern */
s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

struct func_005EAA38_arg0 {
    char pad0[0xBC];
    s32 unkBC;
};

void func_005EAA38(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if ((arg0 + 0xBC) != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0 = ((struct func_005EAA38_arg0 *)arg0)->unkBC;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        ((struct func_005EAA38_arg0 *)arg0)->unkBC = temp_s0;
    }
    func_00227128(arg1, 2);
}
