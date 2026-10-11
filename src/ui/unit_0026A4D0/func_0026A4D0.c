#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00229EE8(s32, s32);                        /* extern */
s32 func_00229F40(s32, s32, s32);               /* extern */
s32 func_0025C110(s32);                             /* extern */
s32 hModule__getName(s32);                             /* extern */

struct func_0026A4D0_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

void func_0026A4D0(struct func_0026A4D0_arg0 *arg0, s32 arg1) {
    s32 temp_s1;
    s32 var_v0;

    temp_s1 = func_0025C110(arg0->unk18);
    var_v0 = arg0->unk1C;
    if (var_v0 == 0) {
        var_v0 = func_00229EE8(temp_s1, hModule__getName(arg0->unk18));
        arg0->unk1C = var_v0;
    }
    func_00229F40(temp_s1, var_v0, arg1);
}
