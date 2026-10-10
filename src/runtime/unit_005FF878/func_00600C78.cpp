#include "types.h"
struct func_00600C78_a0 {
    char pad0[0x28];
    s8 unk28;
};

extern "C" void func_00600C78(struct func_00600C78_a0 *a0, s8 a1) {
    a0->unk28 = a1;
}
