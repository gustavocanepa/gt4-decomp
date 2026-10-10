#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E41E8_arg0 {
    char pad0[0xA4];
    f32 unkA4;
};

void func_005E41E8(struct func_005E41E8_arg0 *arg0, f32 fparg0) {
    arg0->unkA4 = fparg0;
}
