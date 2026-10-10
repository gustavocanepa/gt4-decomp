#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F7418_arg0_unk4 {
    char pad0[0xCC];
    s32 unkCC;
};
struct func_005F7418_arg0 {
    char pad0[0x4];
    struct func_005F7418_arg0_unk4 *unk4;
};

s32 func_005F7418(struct func_005F7418_arg0 *arg0) {
    return arg0->unk4->unkCC;
}
