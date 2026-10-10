#include "types.h"
struct func_00601BC0_a0 {
    char pad0[0x111C];
    s32 unk111C;
};

extern "C" s32 func_00601BC0(struct func_00601BC0_a0 *a0) {
    return a0->unk111C;
}
