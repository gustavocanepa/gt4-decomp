#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CD670_arg0 {
    char pad0[0x11C];
    f32 unk11C;
};

void func_005CD670(struct func_005CD670_arg0 *arg0, f32 fparg0) {
    arg0->unk11C = fparg0;
}
