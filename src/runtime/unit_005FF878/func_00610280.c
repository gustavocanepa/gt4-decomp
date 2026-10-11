#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00610280_arg0 {
    char pad0[0x190];
    s32 unk190;
    s32 unk194;
};

void func_00610280(struct func_00610280_arg0 *arg0) {
    arg0->unk194 = (s32) arg0->unk190;
}
