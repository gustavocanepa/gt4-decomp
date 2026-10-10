#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006014A8_arg0 {
    char pad0[0x81E0];
    s32 unk81E0;
};

s32 func_006014A8(struct func_006014A8_arg0 *arg0) {
    return arg0->unk81E0;
}
