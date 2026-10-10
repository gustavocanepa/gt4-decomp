#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00460960(s32, s32, void *);
struct func_002C3C30_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

void func_002C3C30(void *arg0, s32 arg1) {
    s32 temp_v0;
    temp_v0 = ((struct func_002C3C30_arg0 *)arg0)->unk10;
    if (temp_v0 != 0) {
        ((struct func_002C3C30_arg0 *)arg0)->unk14 = func_00460960(temp_v0, arg1, (s8 *)arg0 + 0x18);
    }
}
