#include "types.h"
struct func_00601AC8_a0 {
    char pad0[0x10E0];
    s32 unk10E0;
};

extern "C" s32 func_00601AC8(struct func_00601AC8_a0 *a0) {
    return a0->unk10E0;
}
