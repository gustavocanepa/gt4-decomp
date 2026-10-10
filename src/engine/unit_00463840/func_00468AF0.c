#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00468860(s32, s32, f32, s32, s32);
s32 func_00468A40(void);
s32 func_00468A60(s32);
s32 func_00468AF0(s32 arg0, s32 arg1, f32 fparg0) {
    s32 temp_s1;
    temp_s1 = func_00468A40();
    return func_00468860(arg0 + 0x8C, arg1, fparg0, temp_s1, func_00468A60(arg0));
}
