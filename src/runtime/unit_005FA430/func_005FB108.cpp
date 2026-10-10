#include "types.h"
struct func_005FB108_a0 {
    char pad0[0x88];
    s32 unk88;
};

extern "C" void func_005FB108(struct func_005FB108_a0 *a0, s32 a1) {
    a0->unk88 = a1;
}
