#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s32 p0; s32 p4; s32 p8; f32 x; u8 pad[0x168]; } E;
s32 func_004080B8(void *, s32);
struct func_00408350_arg0 {
    char pad0[0xC];
    E *unkC;
};

void func_00408350(struct func_00408350_arg0 *arg0, s32 arg1, f32 arg2) {
    if (func_004080B8(arg0, arg1) != 0) {
        E *p = arg0->unkC + arg1;
        p->x = arg2;
    }
}
