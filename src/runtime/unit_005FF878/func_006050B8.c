#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006050B8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
};

void func_006050B8(struct func_006050B8_arg0 *arg0, s32 arg1) {
    arg0->unk1C = arg1;
    arg0->unk20 = 1;
}
