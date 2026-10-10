#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0044A2A8(s32);                         /* extern */

struct func_004078A0_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_004078A0(void *arg0) {
    func_0044A2A8(arg0 + 0xB0);
    ((struct func_004078A0_arg0 *)arg0)->unkA8 = 0;
}
