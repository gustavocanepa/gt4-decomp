#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F5120_arg0 {
    char pad0[0x20];
    f32 unk20;
};

f32 func_005F5120(struct func_005F5120_arg0 *arg0) {
    return arg0->unk20;
}
