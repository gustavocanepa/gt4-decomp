#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F3C18_arg0 {
    char pad0[0xCF54];
    f32 unkCF54;
};

void func_005F3C18(struct func_005F3C18_arg0 *arg0, f32 fparg0) {
    arg0->unkCF54 = (f32) (1.0f / fparg0);
}
