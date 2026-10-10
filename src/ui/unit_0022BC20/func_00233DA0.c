#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00233DA0_arg0 {
    char pad0[0xE4];
    f32 unkE4;
};

void func_00233DA0(struct func_00233DA0_arg0 *arg0, f32 fparg0) {
    arg0->unkE4 = fparg0;
}
