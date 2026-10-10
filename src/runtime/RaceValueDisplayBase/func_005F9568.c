#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F9568_arg0 {
    char pad0[0x24];
    s32 unk24;
};

void func_005F9568(struct func_005F9568_arg0 *arg0, s32 arg1) {
    arg0->unk24 = (s32) ((arg0->unk24 & ~0xFF) | (arg1 & 0xFF));
}
