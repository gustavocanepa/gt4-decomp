/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005AD8E0(s32, s32, s32);               /* extern */
s32 func_005B7788();                                /* extern */
void func_005B78A0();                            /* extern */

extern s32 D_00659690;
void func_005B7918(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = func_005B7788();
    func_005B78A0();
    func_005AD8E0(temp_s0, arg1, D_00659690 + 4);
}
