#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F7328_arg0_unk4 {
    char pad0[0x80];
    s32 unk80;
};
struct func_005F7328_arg0 {
    char pad0[0x4];
    struct func_005F7328_arg0_unk4 *unk4;
};

s32 func_005F7328(struct func_005F7328_arg0 *arg0) {
    return arg0->unk4->unk80;
}
