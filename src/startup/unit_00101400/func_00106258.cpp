#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A0BB0(s32, s32);                    /* extern */

struct func_00106258_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    char pad14[0x20];
    s32 unk34;
    s32 unk38;
};

void func_00106258(void *arg0, s32 arg1, s32 arg2) {
    if ((arg1 != 0) || (arg2 != 0)) {
        ((struct func_00106258_arg0 *)arg0)->unk34 = arg1;
        ((struct func_00106258_arg0 *)arg0)->unk38 = arg2;
        ((struct func_00106258_arg0 *)arg0)->unkC = arg1;
        ((struct func_00106258_arg0 *)arg0)->unk10 = arg2;
    }
    func_004A0BB0(((struct func_00106258_arg0 *)arg0)->unkC, ((struct func_00106258_arg0 *)arg0)->unk10);
}
