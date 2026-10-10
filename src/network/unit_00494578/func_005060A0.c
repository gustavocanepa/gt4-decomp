#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005060A0_arg0 {
    s32 unk0;
    char pad4[0x98];
    s32 unk9C;
};

s32 func_005060A0(struct func_005060A0_arg0 *arg0) {
    s32 var_v0;

    var_v0 = -0xD;
    if (arg0 != NULL) {
        func_005A48D8(arg0, 0, 0xA0);
        arg0->unk0 = 0;
        arg0->unk9C = 0;
        var_v0 = 0;
    }
    return var_v0;
}
