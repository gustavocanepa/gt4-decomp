#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FB920_arg0 {
    char pad0[0x60];
    s32 *unk60;
};

s32 func_005FB920(struct func_005FB920_arg0 *arg0) {
    return *arg0->unk60;
}
