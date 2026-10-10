/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005FB638_arg0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
};

void func_005FB638(struct func_005FB638_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk28 = arg1;
    arg0->unk2C = arg2;
}
