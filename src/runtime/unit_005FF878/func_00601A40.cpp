#include "types.h"
struct func_00601A40_a0 {
    char pad0[0x10C0];
    s32 unk10C0;
};

extern "C" s32 func_00601A40(struct func_00601A40_a0 *a0) {
    return a0->unk10C0;
}
