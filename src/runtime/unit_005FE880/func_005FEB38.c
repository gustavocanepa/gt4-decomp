#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005FEB38_arg0 {
    char pad0[0x178];
    s32 unk178;
};

void func_005FEB38(struct func_005FEB38_arg0 *arg0, s32 arg1) {
    arg0->unk178 = (s32) (arg1 != 0);
}
