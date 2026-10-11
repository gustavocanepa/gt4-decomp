#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F53D0_arg0 {
    char pad0[0xA08];
    f32 unkA08;
};

void func_005F53D0(struct func_005F53D0_arg0 *arg0, f32 fparg0) {
    arg0->unkA08 = fparg0;
}
