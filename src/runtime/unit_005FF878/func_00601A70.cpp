#include "types.h"
struct func_00601A70_a0 {
    char pad0[0x10CC];
    s32 unk10CC;
};

extern "C" s32 func_00601A70(struct func_00601A70_a0 *a0) {
    return a0->unk10CC;
}
