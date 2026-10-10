#include "types.h"
struct func_00601A00_a0 {
    char pad0[0x10B0];
    s32 unk10B0;
};

extern "C" s32 func_00601A00(struct func_00601A00_a0 *a0) {
    return a0->unk10B0;
}
