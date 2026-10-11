#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E7AC8_arg0 {
    char pad0[0x28];
    f32 unk28;
};

void func_005E7AC8(struct func_005E7AC8_arg0 *arg0, f32 fparg0) {
    arg0->unk28 = fparg0;
}
