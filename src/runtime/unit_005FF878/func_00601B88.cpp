#include "types.h"
struct func_00601B88_a0 {
    char pad0[0x110C];
    s32 unk110C;
};

extern "C" void func_00601B88(struct func_00601B88_a0 *a0, s32 a1) {
    a0->unk110C = a1;
}
