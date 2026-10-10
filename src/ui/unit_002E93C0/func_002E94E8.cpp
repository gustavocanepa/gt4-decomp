#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E94E8_arg0 {
    char pad0[0xC0];
    f32 unkC0;
};

void func_002E94E8(void *arg0, f32 fparg0) {
    ((struct func_002E94E8_arg0 *)arg0)->unkC0 = fparg0;
}
