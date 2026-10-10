#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00576788(s32);                         /* extern */
s32 func_005767C0(s32);                         /* extern */

struct func_00109580_var_s0 {
    s32 unk0;
    char pad4[0x4];
    void *unk8;
};

void func_00109580(void **arg0, s32 (*arg1)(s32)) {
    s32 temp_a0;
    s32 temp_s2;
    void *var_s0;

    temp_s2 = (s32)((char *)arg0 + 0xC);
    func_00576788(temp_s2);
    var_s0 = *arg0;
    if (var_s0 != NULL) {
        do {
            temp_a0 = ((struct func_00109580_var_s0 *)var_s0)->unk0;
            var_s0 = ((struct func_00109580_var_s0 *)var_s0)->unk8;
            arg1(temp_a0);
        } while (var_s0 != NULL);
    }
    func_005767C0(temp_s2);
}
