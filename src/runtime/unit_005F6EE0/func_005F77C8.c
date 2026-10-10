/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F77C8_arg0 {
    char pad0[0xB0];
    s32 unkB0;
    s32 unkB4;
};

void func_005F77C8(struct func_005F77C8_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unkB0 = arg1;
    arg0->unkB4 = arg2;
}
