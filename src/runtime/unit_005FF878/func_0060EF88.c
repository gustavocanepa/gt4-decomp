#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0060EF88_arg0 {
    char pad0[0x3F3C];
    s32 unk3F3C;
};

s32 func_0060EF88(struct func_0060EF88_arg0 *arg0) {
    return arg0->unk3F3C != 0;
}
