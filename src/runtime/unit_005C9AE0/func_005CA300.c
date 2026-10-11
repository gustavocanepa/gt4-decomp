#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CA300_arg0 {
    char pad0[0x60];
    f32 unk60;
};

f32 func_005CA300(struct func_005CA300_arg0 *arg0) {
    return arg0->unk60;
}
