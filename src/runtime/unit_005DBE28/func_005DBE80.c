#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005DBE80_arg0 {
    char pad0[0xD0];
    f32 unkD0;
};

void func_005DBE80(struct func_005DBE80_arg0 *arg0, f32 fparg0) {
    arg0->unkD0 = fparg0;
}
