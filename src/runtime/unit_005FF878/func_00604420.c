#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00604420_arg0 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_00604420(struct func_00604420_arg0 *arg0) {
    return arg0->unk8 >= 2;
}
