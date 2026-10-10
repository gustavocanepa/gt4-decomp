#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00436F20(s32, s32, s32);                   /* extern */
s32 func_00438670(s32, s32, s32);               /* extern */

struct func_0018FD88_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0018FD88(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_00438670(func_00436F20(((struct func_0018FD88_arg0 *)arg0)->unk10, arg2, arg4), arg3, arg1);
}
