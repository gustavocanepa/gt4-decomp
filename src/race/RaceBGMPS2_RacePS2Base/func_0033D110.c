#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0033D110_arg0 {
    char pad0[0x8];
    s32 (*unk8)();
    char padC[0x2C];
    s32 unk38;
    char pad3C[0x180];
    f32 unk1BC;
};
struct func_0033D110_var_s0 {
    s32 unk0;
};

void func_0033D110(void *arg0, f32 fparg0) {
    s32 var_v0;
    void *var_s0;

    ((struct func_0033D110_arg0 *)arg0)->unk8();
    ((struct func_0033D110_arg0 *)arg0)->unk1BC = fparg0;
    ((struct func_0033D110_arg0 *)arg0)->unk38 = 0;
    var_s0 = arg0 + 0x13C;
    var_v0 = 0x1F;
    do {
        var_v0 -= 1;
        M2C_FIELD(var_s0, s32 *, -0x100) = 0;
        M2C_FIELD(var_s0, s32 *, -0x80) = 0;
        ((struct func_0033D110_var_s0 *)var_s0)->unk0 = 0;
        var_s0 += 4;
    } while (var_v0 >= 0);
}
