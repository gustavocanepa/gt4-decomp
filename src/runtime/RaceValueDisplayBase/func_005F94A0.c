#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F94A0_arg0 {
    char pad0[0x68];
    f32 unk68;
};

void func_005F94A0(struct func_005F94A0_arg0 *arg0, f32 fparg0) {
    arg0->unk68 = fparg0;
}
