#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F5CF0_arg0 {
    char pad0[0x234];
    f32 unk234;
};

void func_005F5CF0(struct func_005F5CF0_arg0 *arg0, f32 fparg0) {
    arg0->unk234 = fparg0;
}
