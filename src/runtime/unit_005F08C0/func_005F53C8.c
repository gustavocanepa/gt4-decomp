#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F53C8_arg0 {
    char pad0[0xA04];
    f32 unkA04;
};

void func_005F53C8(struct func_005F53C8_arg0 *arg0, f32 fparg0) {
    arg0->unkA04 = fparg0;
}
