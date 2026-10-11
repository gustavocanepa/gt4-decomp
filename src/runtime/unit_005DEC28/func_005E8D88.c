#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E8D88_arg0 {
    char pad0[0x28];
    f32 unk28;
};

void func_005E8D88(struct func_005E8D88_arg0 *arg0, f32 fparg0) {
    arg0->unk28 = fparg0;
}
