#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006036D0_arg0 {
    char pad0[0x93];
    u8 unk93;
};

s32 func_006036D0(struct func_006036D0_arg0 *arg0) {
    return arg0->unk93 * 0x2710;
}
