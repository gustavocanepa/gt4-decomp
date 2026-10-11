#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E8D98_arg0 {
    char pad0[0x2C];
    f32 unk2C;
};

void func_005E8D98(struct func_005E8D98_arg0 *arg0, f32 fparg0) {
    arg0->unk2C = fparg0;
}
