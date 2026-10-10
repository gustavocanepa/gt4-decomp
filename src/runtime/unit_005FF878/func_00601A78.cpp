#include "types.h"
struct func_00601A78_a0 {
    char pad0[0x10CC];
    s32 unk10CC;
};

extern "C" void func_00601A78(struct func_00601A78_a0 *a0, s32 a1) {
    a0->unk10CC = a1;
}
