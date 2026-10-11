#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FD8E0_arg0 {
    char pad0[0x1E678];
    f32 unk1E678;
};

f32 func_005FD8E0(struct func_005FD8E0_arg0 *arg0) {
    return arg0->unk1E678;
}
