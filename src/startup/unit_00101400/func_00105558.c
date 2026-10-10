#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_004AA6B8(s32);
s32 func_004AA570(s32, s32);
struct func_00105558_arg0 {
    s32 unk0;
    char pad4[0x2C];
    s32 unk30;
    s32 unk34;
};

s32 func_00105558(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    if (((struct func_00105558_arg0 *)arg0)->unk34 != 0) {
        func_004AA6B8(((struct func_00105558_arg0 *)arg0)->unk0);
    }
    temp_v0 = func_004AA570(arg1, arg2);
    ((struct func_00105558_arg0 *)arg0)->unk34 = 1;
    ((struct func_00105558_arg0 *)arg0)->unk0 = temp_v0;
    ((struct func_00105558_arg0 *)arg0)->unk30 = 0;
    return temp_v0;
}
