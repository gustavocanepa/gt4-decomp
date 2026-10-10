#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00602CF0_arg0 {
    char pad0[0x40];
    s64 unk40;
};

void func_00602CF0(struct func_00602CF0_arg0 *arg0, s32 arg1) {
    arg0->unk40 = (s64) (arg1 + arg0->unk40);
}
