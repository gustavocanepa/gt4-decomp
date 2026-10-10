/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0060AE60_arg0 {
    char pad0[0x64];
    s32 unk64;
    s32 unk68;
};

void func_0060AE60(struct func_0060AE60_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk64 = arg1;
    arg0->unk68 = arg2;
}
