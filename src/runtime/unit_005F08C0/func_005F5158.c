#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F5158_arg0 {
    char pad0[0x60];
    f32 unk60;
};

f32 func_005F5158(struct func_005F5158_arg0 *arg0) {
    return arg0->unk60;
}
