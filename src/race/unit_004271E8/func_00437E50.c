#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00437E50_arg0 {
    u32 unk0;
    char pad4[0x3];
    s8 unk7;
};
struct func_00437E50_var_a1 {
    char pad0[0x8];
    s8 unk8;
    u8 unk9;
};

void func_00437E50(void *arg0) {
    s8 temp_v1;
    s8 var_a3;
    u32 var_a2;
    void *var_a1;

    var_a3 = 1;
    var_a2 = 0;
    if (((struct func_00437E50_arg0 *)arg0)->unk0 != 0) {
        var_a1 = arg0 + 0x10;
        do {
            var_a2 += 1;
            temp_v1 = ((struct func_00437E50_var_a1 *)var_a1)->unk9 == 0;
            ((struct func_00437E50_var_a1 *)var_a1)->unk8 = temp_v1;
            var_a1 += 0x10;
            var_a3 = (temp_v1 == 0) ? 0 : var_a3;
        } while (var_a2 < (u32) ((struct func_00437E50_arg0 *)arg0)->unk0);
    }
    ((struct func_00437E50_arg0 *)arg0)->unk7 = var_a3;
}
