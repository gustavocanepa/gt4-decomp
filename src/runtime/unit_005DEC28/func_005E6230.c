#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E6230_arg0 {
    char pad0[0xBC];
    f32 unkBC;
};

void func_005E6230(struct func_005E6230_arg0 *arg0, f32 fparg0) {
    arg0->unkBC = fparg0;
}
