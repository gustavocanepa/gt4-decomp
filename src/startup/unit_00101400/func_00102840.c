#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001028F0(void *, s32);             /* extern */
s32 func_0010AA50();                            /* extern */

extern char D_00659BA0[];
struct func_00102840_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x40];
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
};

void func_00102840(struct func_00102840_arg0 *arg0) {
    func_0010AA50();
    arg0->unkA8 = 0;
    arg0->unkAC = 0;
    arg0->unk64 = (s32)D_00659BA0;
    arg0->unkB0 = 0;
    func_001028F0(arg0, 0);
}
