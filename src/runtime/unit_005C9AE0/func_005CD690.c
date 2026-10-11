#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CD690_arg0 {
    char pad0[0x114];
    f32 unk114;
};

void func_005CD690(struct func_005CD690_arg0 *arg0, f32 fparg0) {
    arg0->unk114 = fparg0;
}
