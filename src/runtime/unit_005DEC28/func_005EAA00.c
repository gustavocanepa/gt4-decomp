#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005EAA00_arg0 {
    char pad0[0xEC];
    f32 unkEC;
};

f32 func_005EAA00(struct func_005EAA00_arg0 *arg0) {
    return arg0->unkEC;
}
