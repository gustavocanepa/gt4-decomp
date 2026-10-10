#include "types.h"
struct func_00601A60_a0 {
    char pad0[0x10C8];
    s32 unk10C8;
};

extern "C" s32 func_00601A60(struct func_00601A60_a0 *a0) {
    return a0->unk10C8;
}
