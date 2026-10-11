#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0069E820[];
void hThreadGroup__structor_0(s32);
void func_00309348(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_00323398(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x1C, 4, D_0069E820);
    hThreadGroup__structor_0(temp_v0);
    sp[0] = temp_v0;
    func_00309348(arg0, sp);
}
