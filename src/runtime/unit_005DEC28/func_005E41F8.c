#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E41F8_arg0 {
    char pad0[0xA8];
    f32 unkA8;
};

void func_005E41F8(struct func_005E41F8_arg0 *arg0, f32 fparg0) {
    arg0->unkA8 = fparg0;
}
