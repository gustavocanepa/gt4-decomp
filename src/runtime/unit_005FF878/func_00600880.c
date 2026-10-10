#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00600880_arg0 {
    char pad0[0xC];
    f32 unkC;
};

f32 func_00600880(struct func_00600880_arg0 *arg0) {
    return arg0->unkC;
}
