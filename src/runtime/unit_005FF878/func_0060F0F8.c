#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0060F0F8_arg0_unk5A8 {
    char pad0[0x5B30];
    s32 unk5B30;
};
struct func_0060F0F8_arg0 {
    char pad0[0x5A8];
    struct func_0060F0F8_arg0_unk5A8 *unk5A8;
};

s32 func_0060F0F8(struct func_0060F0F8_arg0 *arg0) {
    return arg0->unk5A8->unk5B30;
}
