#include "types.h"
struct func_00601B40_a0 {
    char pad0[0x10FC];
    s32 unk10FC;
};

extern "C" s32 func_00601B40(struct func_00601B40_a0 *a0) {
    return a0->unk10FC;
}
