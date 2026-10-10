#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00331930(void *, s32, s32);
void func_00331A58(void *, s32, s32);
struct func_003354E8_arg0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x124];
    s32 unk140;
};

void *func_003354E8(void *arg0) {
    void *temp_s1;
    temp_s1 = (s8 *)arg0 + 0xCC;
    if ((((struct func_003354E8_arg0 *)arg0)->unk18 != 0) && (((struct func_003354E8_arg0 *)arg0)->unk140 == 0)) {
        func_00331A58(temp_s1, 0, 0);
        func_00331930(temp_s1, 0, 0);
        ((struct func_003354E8_arg0 *)arg0)->unk140 = 1;
    }
    return temp_s1;
}
