#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E40A8_arg0 {
    char pad0[0x34];
    f32 unk34;
};

void func_005E40A8(struct func_005E40A8_arg0 *arg0, f32 fparg0) {
    arg0->unk34 = fparg0;
}
