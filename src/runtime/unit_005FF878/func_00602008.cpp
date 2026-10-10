#include "types.h"
struct func_00602008_a0 {
    char pad0[0x11CC];
    s32 unk11CC;
};

extern "C" s32 func_00602008(struct func_00602008_a0 *a0) {
    return a0->unk11CC;
}
