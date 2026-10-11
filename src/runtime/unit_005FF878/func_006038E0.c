#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006038E0_arg0 {
    char pad0[0x18];
    s32 *unk18;
};

s32 func_006038E0(struct func_006038E0_arg0 *arg0) {
    return *arg0->unk18;
}
