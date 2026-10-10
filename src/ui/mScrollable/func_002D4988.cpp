#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002D4988_arg0 {
    char pad0[0xB8];
    f32 unkB8;
};

void func_002D4988(void *arg0, f32 fparg0) {
    ((struct func_002D4988_arg0 *)arg0)->unkB8 = fparg0;
}
