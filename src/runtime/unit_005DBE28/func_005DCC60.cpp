#include "types.h"
struct func_005DCC60_a0 {
    char pad0[0x110];
    s32 unk110;
};

extern "C" void func_005DCC60(struct func_005DCC60_a0 *a0, s32 a1) {
    a0->unk110 = a1;
}
