#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void mCarGarage__structor_0(s32);
void func_00309348(s32, s32 *);
s32 malloc(s32);
void func_00148030(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = malloc(0x190);
    mCarGarage__structor_0(temp_v0);
    sp[0] = temp_v0;
    func_00309348(arg0, sp);
}
