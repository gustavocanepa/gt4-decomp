#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CD660_arg0 {
    char pad0[0x118];
    f32 unk118;
};

void func_005CD660(struct func_005CD660_arg0 *arg0, f32 fparg0) {
    arg0->unk118 = fparg0;
}
