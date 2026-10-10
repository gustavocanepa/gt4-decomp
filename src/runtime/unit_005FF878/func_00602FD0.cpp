#include "types.h"
struct func_00602FD0_a0 {
    char pad0[0x24];
    s32 unk24;
};

extern "C" s32 func_00602FD0(struct func_00602FD0_a0 *a0) {
    return a0->unk24;
}
