#include "types.h"
struct func_005FADC0_a0 {
    char pad0[0x11E4];
    s32 unk11E4;
};

extern "C" void func_005FADC0(struct func_005FADC0_a0 *a0, s32 a1) {
    a0->unk11E4 = a1;
}
