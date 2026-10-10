#include "types.h"
struct func_005FADE0_a0 {
    char pad0[0x11EC];
    s32 unk11EC;
};

extern "C" s32 func_005FADE0(struct func_005FADE0_a0 *a0) {
    return a0->unk11EC;
}
