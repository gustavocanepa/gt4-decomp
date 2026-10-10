#include "types.h"
struct func_005E7000_a0 {
    char pad0[0x110];
    s32 unk110;
};

extern "C" s32 func_005E7000(struct func_005E7000_a0 *a0) {
    return a0->unk110;
}
