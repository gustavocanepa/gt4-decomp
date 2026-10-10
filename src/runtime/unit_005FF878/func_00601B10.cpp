#include "types.h"
struct func_00601B10_a0 {
    char pad0[0x10F0];
    s32 unk10F0;
};

extern "C" s32 func_00601B10(struct func_00601B10_a0 *a0) {
    return a0->unk10F0;
}
