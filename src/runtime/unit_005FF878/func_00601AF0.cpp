#include "types.h"
struct func_00601AF0_a0 {
    char pad0[0x10E8];
    s32 unk10E8;
};

extern "C" s32 func_00601AF0(struct func_00601AF0_a0 *a0) {
    return a0->unk10E8;
}
