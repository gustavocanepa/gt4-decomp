#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

/* A member array indexed by a variable: base + index (a struct field), not index + base. */
#define M2C_ARRAY(base, T, off, idx) (((struct { char pad[off]; T a[1]; } *)(base))->a[idx])

void *func_00359538(void *);
s32 func_00359F50(void *);
f32 func_0035A008(f32, f32);

struct func_003F7E20_temp_v0 {
    char pad0[0x1];
    u8 unk1;
};
struct func_003F7E20_temp_s1 {
    char pad0[0x468];
    f32 unk468;
    char pad46C[0x100];
    f32 unk56C;
    char pad570[0x8];
    f32 unk578;
};

f32 func_003F7E20(void *arg0, s32 arg1) {
    f32 var_f0;
    s32 var_v0;
    struct func_003F7E20_temp_s1 *temp_s1;
    struct func_003F7E20_temp_v0 *temp_v0;

    temp_v0 = func_00359538(arg0);
    temp_s1 = arg0 + 0x104;
    var_f0 = 0x0.0p+0f;
    var_v0 = 0;
    if (arg1 < (s32) temp_v0->unk1) {
        var_v0 = M2C_ARRAY(temp_v0, s8, 0x3C, arg1) > 0;
    }
    if (var_v0 != 0) {
        var_f0 = temp_s1->unk468 * func_0035A008(M2C_FIELD(func_00359F50(arg0), f32 *, 0x30), temp_s1->unk56C - temp_s1->unk578);
    }
    return var_f0;
}
