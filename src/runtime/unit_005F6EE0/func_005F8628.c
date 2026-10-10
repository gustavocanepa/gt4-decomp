/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F8628_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

void func_005F8628(struct func_005F8628_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk18 = arg1;
    arg0->unk1C = arg2;
}
