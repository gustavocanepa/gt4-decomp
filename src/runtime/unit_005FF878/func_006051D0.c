#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006051D0_arg0 {
    char pad0[0x20];
    s32 unk20;
    s32 unk24;
    char pad28[0xA40];
    s32 unkA68;
};

s32 func_006051D0(struct func_006051D0_arg0 *arg0, s32 arg1) {
    return arg0->unkA68 + ((arg1 * (arg0->unk24 * arg0->unk20)) << 8);
}
