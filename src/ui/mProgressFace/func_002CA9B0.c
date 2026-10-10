#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_0069C7E8[];
void mProgressFace__structor_0(s32);
void func_002A0CF0(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_002CA9B0(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x100, 4, D_0069C7E8);
    mProgressFace__structor_0(temp_v0);
    sp[0] = temp_v0;
    func_002A0CF0(arg0, sp);
}
