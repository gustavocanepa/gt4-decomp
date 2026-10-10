#include "types.h"
struct func_00600058_a0 {
    char pad0[0x14C];
    s32 unk14C;
};

extern "C" void func_00600058(struct func_00600058_a0 *a0, s32 a1) {
    a0->unk14C = a1;
}
