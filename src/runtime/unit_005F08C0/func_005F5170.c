#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F5170_arg0 {
    char pad0[0x70];
    f32 unk70;
};

f32 func_005F5170(struct func_005F5170_arg0 *arg0) {
    return arg0->unk70;
}
