#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FD820_arg0 {
    char pad0[0x1E650];
    s32 unk1E650;
};

s32 func_005FD820(struct func_005FD820_arg0 *arg0) {
    return arg0->unk1E650;
}
