#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E4200_arg0 {
    char pad0[0xA8];
    f32 unkA8;
};

f32 func_005E4200(struct func_005E4200_arg0 *arg0) {
    return arg0->unkA8;
}
