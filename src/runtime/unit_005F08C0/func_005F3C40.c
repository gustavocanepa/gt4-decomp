#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3C40_arg0 {
    char pad0[0xCF54];
    f32 unkCF54;
};

void func_005F3C40(struct func_005F3C40_arg0 *arg0, f32 fparg0) {
    arg0->unkCF54 = (f32) (-1.0f / fparg0);
}
