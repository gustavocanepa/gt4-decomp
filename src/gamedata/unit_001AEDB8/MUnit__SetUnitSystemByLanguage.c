#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char PDISTD__UNIT_MANAGER[];
void func_00312318(void *, s32);
void func_00312370(void *, s32);
s32 func_00314AD8(s32);
void func_00472528(void *, s32);
s32 func_0048ED30(s32);
void MUnit__SetUnitSystemByLanguage(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    s32 temp_s0;
    if (arg1 > 0) {
        func_00312370(sp, arg2);
        temp_s0 = func_0048ED30(func_00314AD8(sp[0]));
        func_00312318(sp, 2);
        func_00472528(PDISTD__UNIT_MANAGER, temp_s0);
    }
}
