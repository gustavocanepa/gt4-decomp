#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3E08_arg0 {
    char pad0[0xE330];
    s32 unkE330;
};

s32 func_005F3E08(struct func_005F3E08_arg0 *arg0) {
    return arg0->unkE330;
}
