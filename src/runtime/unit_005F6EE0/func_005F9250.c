#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F9250_arg0 {
    char pad0[0x24];
    f32 unk24;
};

void func_005F9250(struct func_005F9250_arg0 *arg0, f32 fparg0) {
    arg0->unk24 = fparg0;
}
