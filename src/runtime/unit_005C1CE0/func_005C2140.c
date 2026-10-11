#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005C2140_arg0 {
    char pad0[0xA8];
    f32 unkA8;
};

f32 func_005C2140(struct func_005C2140_arg0 *arg0) {
    return arg0->unkA8;
}
