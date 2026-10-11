#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F8D98_arg0 {
    char pad0[0x54];
    s32 unk54;
};

void func_005F8D98(struct func_005F8D98_arg0 *arg0, s32 arg1) {
    arg0->unk54 = (s32) ((arg0->unk54 & 0xFFFFFF) | (arg1 << 0x18));
}
