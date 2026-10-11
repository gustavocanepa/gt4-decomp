#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004A91A8_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
};

s32 func_004A91A8(struct func_004A91A8_arg0 *arg0) {
    return arg0->unkC + arg0->unk10;
}
