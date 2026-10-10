#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E8420_arg0 {
    char pad0[0x100];
    f32 unk100;
};

void func_005E8420(struct func_005E8420_arg0 *arg0, f32 fparg0) {
    arg0->unk100 = fparg0;
}
