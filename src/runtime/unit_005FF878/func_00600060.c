#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00600060_arg0 {
    char pad0[0x198];
    s32 unk198;
};

s32 func_00600060(struct func_00600060_arg0 *arg0) {
    return arg0->unk198 != 0;
}
