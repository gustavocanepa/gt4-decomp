#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F7DF0_arg0 {
    char pad0[0x8];
    f32 unk8;
};

void func_005F7DF0(struct func_005F7DF0_arg0 *arg0, f32 fparg0) {
    arg0->unk8 = fparg0;
}
