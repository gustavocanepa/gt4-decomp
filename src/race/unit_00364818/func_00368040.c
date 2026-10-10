#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00368040_arg0_unk10 {
    char pad0[0x247];
    u8 unk247;
};
struct func_00368040_arg0 {
    char pad0[0x10];
    struct func_00368040_arg0_unk10 *unk10;
};

f32 func_00368040(struct func_00368040_arg0 *arg0) {
    f32 var_f0;
    u8 temp_a0;

    var_f0 = 0x1.05cca20000000p+9f;
    temp_a0 = arg0->unk10->unk247;
    if (temp_a0 != 3) {
        var_f0 = 0x1.d73d240000000p+8f;
        if (temp_a0 != 2) {
            var_f0 = 0x1.a2e1040000000p+8f;
        }
    }
    return var_f0;
}
