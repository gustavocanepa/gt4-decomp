#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006008F0_arg0 {
    char pad0[0xC];
    f32 unkC;
};

f32 func_006008F0(struct func_006008F0_arg0 *arg0) {
    return arg0->unkC;
}
