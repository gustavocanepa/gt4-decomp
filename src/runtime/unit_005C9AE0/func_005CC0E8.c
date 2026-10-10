#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CC0E8_arg0_unk10 {
    char pad0[0x78];
    s32 unk78;
};
struct func_005CC0E8_arg0 {
    char pad0[0x10];
    struct func_005CC0E8_arg0_unk10 *unk10;
};

s32 func_005CC0E8(struct func_005CC0E8_arg0 *arg0) {
    return arg0->unk10->unk78;
}
