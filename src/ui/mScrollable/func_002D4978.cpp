#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002D4978_arg0 {
    char pad0[0xB4];
    f32 unkB4;
};

void func_002D4978(void *arg0, f32 fparg0) {
    ((struct func_002D4978_arg0 *)arg0)->unkB4 = fparg0;
}
