#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00697E58[];
void mModelStream__structor_0(s32);
void func_001FC378(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_0021CA08(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x2C, 4, D_00697E58);
    mModelStream__structor_0(temp_v0);
    sp[0] = temp_v0;
    func_001FC378(arg0, sp);
}
