#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_005F6688_arg0_unk6C {
    char pad0[0x80];
    void *unk80;
};
struct func_005F6688_arg0 {
    char pad0[0x6C];
    struct func_005F6688_arg0_unk6C *unk6C;
};

s32 func_005F6688(struct func_005F6688_arg0 *arg0) {
    return M2C_FIELD(arg0->unk6C->unk80, s32 *, 4);
}
