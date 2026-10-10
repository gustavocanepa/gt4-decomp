#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CC4A8_arg0_unk10 {
    char pad0[0x10E8];
    s32 unk10E8;
};
struct func_005CC4A8_arg0 {
    char pad0[0x10];
    struct func_005CC4A8_arg0_unk10 *unk10;
};

s32 func_005CC4A8(struct func_005CC4A8_arg0 *arg0) {
    return arg0->unk10->unk10E8;
}
