#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00380D98_arg0_unk184 {
    char pad0[0x6F];
    u8 unk6F;
};
struct func_00380D98_arg0 {
    char pad0[0x184];
    struct func_00380D98_arg0_unk184 *unk184;
};

s32 func_00380D98(struct func_00380D98_arg0 *arg0) {
    return arg0->unk184->unk6F ^ 1;
}
