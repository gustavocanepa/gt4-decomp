#include "types.h"
struct func_00601AA0_a0 {
    char pad0[0x10D8];
    s32 unk10D8;
};

extern "C" s32 func_00601AA0(struct func_00601AA0_a0 *a0) {
    return a0->unk10D8;
}
