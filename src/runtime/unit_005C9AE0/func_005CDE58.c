#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CDE58_arg0 {
    char pad0[0xF8];
    f32 unkF8;
};

f32 func_005CDE58(struct func_005CDE58_arg0 *arg0) {
    return arg0->unkF8;
}
