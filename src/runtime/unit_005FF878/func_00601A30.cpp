#include "types.h"
struct func_00601A30_a0 {
    char pad0[0x10BC];
    s32 unk10BC;
};

extern "C" s32 func_00601A30(struct func_00601A30_a0 *a0) {
    return a0->unk10BC;
}
