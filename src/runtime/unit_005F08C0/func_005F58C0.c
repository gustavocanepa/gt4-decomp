#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F58C0_arg0 {
    char pad0[0x14C];
    f32 unk14C;
};

void func_005F58C0(struct func_005F58C0_arg0 *arg0, f32 fparg0) {
    arg0->unk14C = fparg0;
}
