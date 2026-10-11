#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    s32 unkC[1]; /* indexed by func_0042D9F0() */
} S_0042DA58;

s32 func_0042D9F0();
f32 func_0042DC00(s32, f32);

void func_0042DA58(S_0042DA58 *arg0, f32 fparg0) {
    arg0->unk8 = func_0042DC00(arg0->unkC[func_0042D9F0()], fparg0);
}
