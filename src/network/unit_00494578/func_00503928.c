/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005037A0(s32);                         /* extern */
s32 func_00574D78();                            /* extern */
s32 func_0060F9B8(s32);                         /* extern */

struct func_00503928_arg0 {
    char pad0[0x954];
    s32 unk954;
    s32 unk958;
};

void func_00503928(void *arg0) {
    s32 var_a0;
    s32 var_s0;
    s32 var_s1;

    var_s0 = arg0 + 0x54;
    var_s1 = 0x1F;
    func_00574D78();
    func_0060F9B8(arg0 + 0x30);
    func_0060F9B8(arg0 + 0x3C);
    func_0060F9B8(arg0 + 0x48);
    var_a0 = var_s0;
    do {
        var_s0 += 0x48;
        var_s1 -= 1;
        func_005037A0(var_a0);
        var_a0 = var_s0;
    } while (var_s1 != -1);
    ((struct func_00503928_arg0 *)arg0)->unk954 = 0;
    ((struct func_00503928_arg0 *)arg0)->unk958 = 0;
}
