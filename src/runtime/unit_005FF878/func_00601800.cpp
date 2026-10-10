#include "types.h"
struct func_00601800_a0 {
    char pad0[0x70];
    s32 unk70;
};

extern "C" s32 func_00601800(struct func_00601800_a0 *a0) {
    return a0->unk70;
}
