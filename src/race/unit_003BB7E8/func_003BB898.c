#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003BB898_arg0 {
    char pad0[0x40];
    u32 unk40;
};

s32 func_003BB898(struct func_003BB898_arg0 *arg0, u32 arg1) {
    u32 temp_v1;

    temp_v1 = arg0->unk40;
    if ((temp_v1 == 0x157529FF) || (arg1 < temp_v1)) {
        arg0->unk40 = arg1;
        return 1;
    }
    return 0;
}
