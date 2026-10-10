#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003454A8(void *);                      /* extern */
void *func_0034C190(void *, s32);                   /* extern */

struct func_003F88E8_arg0 {
    char pad0[0xF858];
    u8 unkF858;
    char padF859[0x47];
    s32 unkF8A0;
};
struct func_003F88E8_temp_v0 {
    char pad0[0x56A];
    s8 unk56A;
};

void func_003F88E8(struct func_003F88E8_arg0 *arg0) {
    s32 var_s0;
    struct func_003F88E8_temp_v0 *temp_v0;

    if (arg0->unkF858 != 0) {
        var_s0 = 0;
        if (arg0->unkF8A0 > 0) {
            do {
                temp_v0 = func_0034C190(arg0, var_s0);
                var_s0 += 1;
                if (temp_v0->unk56A == 2) {
                    func_003454A8(temp_v0);
                }
            } while (var_s0 < arg0->unkF8A0);
        }
    }
}
