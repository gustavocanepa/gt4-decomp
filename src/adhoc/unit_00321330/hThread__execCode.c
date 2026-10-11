#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00309360(s32, void *);                 /* extern */
s32 HCodeFrame__structor_0(void *, s32 *);                   /* extern */
s32 hThread__execute(void *, s32);                     /* extern */
s32 hThread__setArguments(void *, s32, s32, s32, s32);  /* extern */

struct func_00321F70_temp_v1 {
    u8 pad0[0x20];
    s32 unk20;
};

struct func_00321F70_arg1 {
    char pad0[0x2C];
    void *unk2C;
    char pad30[0x4];
    s32 unk34;
    char pad38[0xC];
    s32 unk44;
    s32 unk48;
};

s32 hThread__execCode(s32 arg0, void *arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_s5;
    struct func_00321F70_temp_v1 *temp_v1;

    temp_s5 = HCodeFrame__structor_0(arg1, arg2);
    hThread__setArguments(arg1, *arg2 + 0x10, arg4, arg5, arg3);
    do {

    } while (hThread__execute(arg1, temp_s5) == 2);
    if (((struct func_00321F70_arg1 *)arg1)->unk34 == 1) {
        temp_v1 = ((struct func_00321F70_arg1 *)arg1)->unk2C;
        temp_v1->unk20 = (s32) (temp_v1->unk20 - 1);
    }
    ((struct func_00321F70_arg1 *)arg1)->unk34 = 3;
    ((struct func_00321F70_arg1 *)arg1)->unk48 = (s32) ((struct func_00321F70_arg1 *)arg1)->unk44;
    func_00309360(arg0, arg1 + 0x30);
    return arg0;
}
