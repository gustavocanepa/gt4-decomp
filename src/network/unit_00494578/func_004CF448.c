#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004CF448_arg0 {
    char pad0[0x58];
    s32 unk58;
    char pad5C[0xDC];
    s8 unk138;
};

void func_004CF448(struct func_004CF448_arg0 *arg0, s32 arg1) {
    arg0->unk58 = arg1;
    arg0->unk138 = 0;
}
