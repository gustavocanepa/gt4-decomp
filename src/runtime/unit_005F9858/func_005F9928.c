#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F9928_arg0 {
    char pad0[0x3C];
    f32 unk3C;
};

void func_005F9928(struct func_005F9928_arg0 *arg0, f32 fparg0) {
    arg0->unk3C = fparg0;
}
