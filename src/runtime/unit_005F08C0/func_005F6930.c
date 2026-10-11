/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005F6930_arg0 {
    char pad0[0xD20];
    s32 unkD20;
    s32 unkD24;
};

void func_005F6930(struct func_005F6930_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unkD20 = arg1;
    arg0->unkD24 = arg2;
}
