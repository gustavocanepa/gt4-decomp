#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

void **func_00444010(s32, s32);                 /* extern */
s32 func_00448420();                                /* extern */
s32 func_0057F260(s32);                             /* extern */
s32 func_005A6AB0(s32, s32, s32, s32 *);        /* extern */

extern char D_006235A8[];
struct func_00448458_temp_a1 {
    char pad0[0x4];
    u32 unk4;
};

s32 func_00448458(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_a3;
    s32 temp_v0;
    s32 temp_v1;
    void *temp_a1;

    temp_v0 = func_00448420();
    if ((temp_v0 >= 0) && (arg1 < temp_v0)) {
        temp_a1 = *func_00444010((s32)D_006235A8, arg0);
        temp_v1 = temp_a1 + 0x10;
        temp_a3 = temp_v1 + (arg1 * 8);
        func_005A6AB0(arg2, temp_v1 + (((struct func_00448458_temp_a1 *)temp_a1)->unk4 * 8) + (*temp_a3 + 2), arg3, temp_a3);
        M2C_FIELD((arg2 + arg3), s8 *, -1) = 0;
        return func_0057F260(arg2);
    }
    return -1;
}
