#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00601488_arg0 {
    char pad0[0x81F0];
    s32 unk81F0;
};

s32 func_00601488(struct func_00601488_arg0 *arg0) {
    return arg0->unk81F0;
}
