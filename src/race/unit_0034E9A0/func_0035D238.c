#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0035D238_arg0 {
    char pad0[0x788];
    u8 unk788;
};

s32 func_0035D238(struct func_0035D238_arg0 *arg0) {
    return arg0->unk788 == 0x22;
}
