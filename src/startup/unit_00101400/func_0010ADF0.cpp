#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_00576788(s32);                         /* extern */
s32 func_005767C0(s32);                         /* extern */
s32 func_005767E0(s32);                         /* extern */

struct func_0010ADF0_arg0 {
    char pad0[0xA0];
    s32 unkA0;
};

void func_0010ADF0(char *arg0) {
    s32 temp_s1;

    temp_s1 = (s32)(arg0 + 0x6C);
    func_00576788(temp_s1);
    if (((struct func_0010ADF0_arg0 *)arg0)->unkA0 != 0) {
        func_005767E0(temp_s1);
    }
    func_005767C0(temp_s1);
}

}
