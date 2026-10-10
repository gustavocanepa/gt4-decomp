#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CBDF0_arg0 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_005CBDF0(struct func_005CBDF0_arg0 *arg0) {
    return arg0->unk10 + 0x1184;
}
