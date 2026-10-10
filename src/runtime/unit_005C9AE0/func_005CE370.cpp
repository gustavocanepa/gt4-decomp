#include "types.h"
struct func_005CE370_a0 {
    char pad0[0x1F50];
    s32 unk1F50;
};

extern "C" void func_005CE370(struct func_005CE370_a0 *a0, s32 a1) {
    a0->unk1F50 = a1;
}
