#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E83C8_arg0 {
    char pad0[0xF4];
    f32 unkF4;
};

void func_005E83C8(struct func_005E83C8_arg0 *arg0, f32 fparg0) {
    arg0->unkF4 = fparg0;
}
