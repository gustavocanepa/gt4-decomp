/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005F3EF8_arg0 {
    char pad0[0xD84];
    s32 unkD84;
    s32 unkD88;
};

void func_005F3EF8(struct func_005F3EF8_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unkD84 = arg1;
    arg0->unkD88 = arg2;
}
