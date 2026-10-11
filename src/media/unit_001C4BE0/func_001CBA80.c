#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_001CBA80_arg0 {
    char pad0[0x2C];
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
};

s32 func_001CBA80(struct func_001CBA80_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg1 == arg0->unk38) && ((arg0->unk2C == arg2) || (arg0->unk30 == arg2)) && ((arg3 == 0) || (arg0->unk34 == arg3) || (arg0->unk3C == arg3))) {
        var_v1 = 1;
    }
    return var_v1;
}
