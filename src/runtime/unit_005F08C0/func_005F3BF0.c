#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3BF0_arg0 {
    char pad0[0xCF50];
    f32 unkCF50;
};

void func_005F3BF0(struct func_005F3BF0_arg0 *arg0, f32 fparg0) {
    arg0->unkCF50 = (f32) (-1.0f / fparg0);
}
