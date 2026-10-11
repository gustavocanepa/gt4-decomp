#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00559C20_arg0_unk14 {
    char pad0[0x4];
    s32 unk4;
};
struct func_00559C20_arg0 {
    char pad0[0x14];
    struct func_00559C20_arg0_unk14 *unk14;
};

s32 func_00559C20(struct func_00559C20_arg0 *arg0) {
    return arg0->unk14->unk4;
}
