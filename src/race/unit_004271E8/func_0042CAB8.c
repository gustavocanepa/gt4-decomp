#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0042CAB8_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_0042CAB8(struct func_0042CAB8_arg0 *arg0) {
    arg0->unk8 = (s32) (arg0->unk8 - 1);
}
