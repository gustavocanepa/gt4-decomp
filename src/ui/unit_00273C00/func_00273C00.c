#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00454410(void *);
s32 func_00454580(void *);
void func_00454698(s32, s32 *, s32, s32);
struct func_00273C00_arg0_unk8 {
    char pad0[0x7C];
    s32 *unk7C;
};
struct func_00273C00_arg0 {
    char pad0[0x8];
    struct func_00273C00_arg0_unk8 *unk8;
    s32 unkC;
};

s32 func_00273C00(struct func_00273C00_arg0 *arg0, void *arg1, s32 arg2) {
    s32 *temp_a1;
    s32 var_v0;
    var_v0 = func_00454580(arg1);
    if (var_v0 != 0) {
        arg0->unkC = arg2;
        arg0->unk8 = arg1;
        func_00454410(arg1);
        temp_a1 = arg0->unk8->unk7C;
        func_00454698(*temp_a1, temp_a1, 0, 0);
        var_v0 = 1;
    }
    return var_v0;
}
