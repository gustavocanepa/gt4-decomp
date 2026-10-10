/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005B0BB0(s32, s32, s32);   /* extern */
s32 func_005B72A8();                                /* extern */
s32 func_005B72F8();                            /* extern */

extern s32 D_00655EE4;
extern s32 D_00655F08;
void func_005803E0();
s32 func_00580438(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_s0;

    D_00655EE4 = 1;
    temp_s0 = func_005B72A8();
    func_005B0BB0(0x80000012, func_005803E0, 0);
    if (temp_s0 != 0) {
        func_005B72F8();
    }
    D_00655EE4 = 0;
    D_00655F08 = 1;
    return 1;
}
