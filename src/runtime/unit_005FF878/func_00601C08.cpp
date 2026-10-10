#include "types.h"
struct func_00601C08_a0 {
    char pad0[0x112C];
    s32 unk112C;
};

extern "C" void func_00601C08(struct func_00601C08_a0 *a0, s32 a1) {
    a0->unk112C = a1;
}
