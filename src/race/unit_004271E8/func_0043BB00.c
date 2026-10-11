#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043B808(void *, s32);             /* extern */

extern char D_00623358[];
extern char D_00623390[];
extern char D_00688210[];
struct func_0043BB00_arg0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    char pad10[0x1D];
    s8 unk2D;
};

s32 func_0043BB00(struct func_0043BB00_arg0 *arg0) {
    func_004383D8(arg0, (s32)D_00623358, (s32)D_00623390, arg0->unk8);
    arg0->unkC = (s32)D_00688210;
    func_0043B808(arg0, 0);
    arg0->unk2D = 1;
}
