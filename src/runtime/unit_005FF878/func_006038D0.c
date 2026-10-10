#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_006038D0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_006038D0(struct func_006038D0_arg0 *arg0, s32 arg1) {
    return arg0->unk14 + (arg1 * 8);
}
