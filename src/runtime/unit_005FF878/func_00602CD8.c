#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00602CD8_arg0 {
    char pad0[0x48];
    s64 unk48;
};

void func_00602CD8(struct func_00602CD8_arg0 *arg0, s32 arg1) {
    arg0->unk48 = (s64) (arg1 + arg0->unk48);
}
