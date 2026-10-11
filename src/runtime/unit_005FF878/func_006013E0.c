#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006013E0_arg0 {
    char pad0[0x81C8];
    s32 unk81C8;
};

void func_006013E0(struct func_006013E0_arg0 *arg0, s32 arg1) {
    arg0->unk81C8 = arg1;
}
