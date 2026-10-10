#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00568B40(s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_005692C0(s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_00569938(s32, s32, s32, s32, s32, s32); /* extern */

extern char D_00655348[];
extern char D_0065534C[];
void func_00568A38(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;

    func_00569938(*(s32 *)(s32)D_00655348, arg0, arg1, arg2, arg3, arg4);
    temp_s3 = arg2 >> 1;
    temp_s5 = arg3 >> 1;
    temp_s4 = arg4 >> 1;
    temp_s2 = arg1 >> 1;
    func_00568B40(*(s32 *)(s32)D_0065534C, *(s32 *)(s32)D_00655348, arg1, arg2, arg3, arg4, arg5);
    func_005692C0(*(s32 *)(s32)D_0065534C + 0x100, *(s32 *)(s32)D_00655348 + 0x400, temp_s2, temp_s3, temp_s5, temp_s4, arg5);
    func_005692C0(*(s32 *)(s32)D_0065534C + 0x140, *(s32 *)(s32)D_00655348 + 0x500, temp_s2, temp_s3, temp_s5, temp_s4, arg5);
}
