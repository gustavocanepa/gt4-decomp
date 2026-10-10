#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

u16 func_003F1E30(void *, s32);
struct func_0036BEE0_arg0_unk10 {
    char pad0[0x262];
    u16 unk262;
};
struct func_0036BEE0_arg0 {
    char pad0[0x10];
    struct func_0036BEE0_arg0_unk10 *unk10;
    char pad14[0x554];
    s32 unk568;
};

u16 func_0036BEE0(struct func_0036BEE0_arg0 *arg0) {
    u16 var_a1;
    var_a1 = arg0->unk10->unk262;
    if ((arg0->unk568 & 0xFFFF0000) == 0x10000) {
        var_a1 = func_003F1E30(arg0, (s32) var_a1);
    }
    return var_a1;
}
