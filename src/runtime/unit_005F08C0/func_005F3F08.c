/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005F3F08_arg0 {
    char pad0[0xD8C];
    s32 unkD8C;
    s32 unkD90;
};

void func_005F3F08(struct func_005F3F08_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unkD8C = arg1;
    arg0->unkD90 = arg2;
}
