#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_003575E0(void *, f32, f32);                /* extern */
void *func_00359538();                              /* extern */

struct func_00357690_temp_v0 {
    char pad0[0x1];
    u8 unk1;
};

struct func_00357690_var_s0 {
    char pad0[0x18C];
    f32 unk18C;
    f32 unk190;
    f32 unk194;
};

void func_00357690(void *arg0) {
    s32 var_s2;
    struct func_00357690_temp_v0 *temp_v0;
    void *var_s0;

    var_s0 = arg0;
    var_s2 = 0;
    temp_v0 = func_00359538();
    if (temp_v0->unk1 != 0) {
        do {
            var_s2 += 1;
            ((struct func_00357690_var_s0 *)var_s0)->unk194 = func_003575E0(var_s0 + 0x1C4, ((struct func_00357690_var_s0 *)var_s0)->unk18C, ((struct func_00357690_var_s0 *)var_s0)->unk190);
            var_s0 += 0xEC;
        } while (var_s2 < (s32) temp_v0->unk1);
    }
}
