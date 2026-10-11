#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E40C0_arg0 {
    char pad0[0x3C];
    f32 unk3C;
};

f32 func_005E40C0(struct func_005E40C0_arg0 *arg0) {
    return arg0->unk3C;
}
