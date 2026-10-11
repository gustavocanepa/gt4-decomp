#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00601AD0_arg0 {
    char pad0[0x10E0];
    s32 unk10E0;
};

void func_00601AD0(struct func_00601AD0_arg0 *arg0, s32 arg1) {
    arg0->unk10E0 = (s32) (arg1 != 0);
}
