#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E5B58_arg0 {
    char pad0[0xB0];
    f32 unkB0;
};

void func_005E5B58(struct func_005E5B58_arg0 *arg0, f32 fparg0) {
    arg0->unkB0 = fparg0;
}
