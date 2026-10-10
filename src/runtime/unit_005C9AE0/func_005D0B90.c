/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005D0B90_arg0 {
    char pad0[0x264];
    s32 unk264;
    s32 unk268;
};

void func_005D0B90(struct func_005D0B90_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk264 = arg1;
    arg0->unk268 = arg2;
}
