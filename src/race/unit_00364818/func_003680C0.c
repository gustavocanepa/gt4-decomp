#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_003680C0_arg0_unk10 {
    char pad0[0x247];
    u8 unk247;
};
struct func_003680C0_arg0 {
    char pad0[0x10];
    struct func_003680C0_arg0_unk10 *unk10;
};

f32 func_003680C0(struct func_003680C0_arg0 *arg0) {
    f32 var_f0;

    var_f0 = -1047.1974f;
    if (arg0->unk10->unk247 != 3) {
        var_f0 = -680.6783f;
    }
    return var_f0;
}
