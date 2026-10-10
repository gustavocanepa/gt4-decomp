#include "types.h"
struct func_00602D60_a0 {
    char pad0[0x80];
    s32 unk80;
};

extern "C" s32 func_00602D60(struct func_00602D60_a0 *a0) {
    return a0->unk80;
}
