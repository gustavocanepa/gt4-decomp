#include "types.h"
struct func_00601AB0_a0 {
    char pad0[0x10DC];
    s32 unk10DC;
};

extern "C" s32 func_00601AB0(struct func_00601AB0_a0 *a0) {
    return a0->unk10DC;
}
