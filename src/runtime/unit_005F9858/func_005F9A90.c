/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F9A90_arg0 {
    char pad0[0x24];
    s32 unk24;
    s32 unk28;
};

void func_005F9A90(struct func_005F9A90_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk24 = arg1;
    arg0->unk28 = arg2;
}
