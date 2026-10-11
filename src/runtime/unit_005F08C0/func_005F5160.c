#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F5160_arg0 {
    char pad0[0x64];
    f32 unk64;
};

f32 func_005F5160(struct func_005F5160_arg0 *arg0) {
    return arg0->unk64;
}
