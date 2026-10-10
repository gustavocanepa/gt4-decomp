#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00277328_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

s32 func_00277328(struct func_00277328_arg0 *arg0, s32 arg1) {
    if (arg1 < arg0->unk4) {
        return arg0->unk8 + (arg1 << 5) + 4;
    }
    return 0;
}
