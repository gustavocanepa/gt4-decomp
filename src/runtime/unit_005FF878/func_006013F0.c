#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006013F0_arg0 {
    char pad0[0x81C8];
    s32 unk81C8;
};

s32 func_006013F0(struct func_006013F0_arg0 *arg0) {
    return arg0->unk81C8;
}
