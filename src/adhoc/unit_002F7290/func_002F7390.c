#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_0069D808[];
void hFileIO__structor_0(s32, s32);
void func_002FEA80(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_002F7390(s32 arg0, s32 arg1) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0xFC, 4, D_0069D808);
    hFileIO__structor_0(temp_v0, arg1);
    sp[0] = temp_v0;
    func_002FEA80(arg0, sp);
}
