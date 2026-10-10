#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003E7488_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_003E7488(struct func_003E7488_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    return temp_v0;
}
