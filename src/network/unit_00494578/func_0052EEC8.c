#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052EEC8_arg0 {
    s32 unk0;
    char pad4[0x18];
    s32 unk1C;
};

s32 func_0052EEC8(struct func_0052EEC8_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        func_005A48D8(arg0, 0, 0x48);
        arg0->unk1C = 2;
        arg0->unk0 = 1;
        var_v0 = 0;
    }
    return var_v0;
}
