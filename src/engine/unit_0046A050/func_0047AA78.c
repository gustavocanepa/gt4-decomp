#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004774A8(s32);                             /* extern */

struct func_0047AA78_arg0 {
    char pad0[0x74];
    s32 unk74;
};

void func_0047AA78(struct func_0047AA78_arg0 *arg0, s32 arg1) {
    arg0->unk74 = func_004774A8(arg1);
}
