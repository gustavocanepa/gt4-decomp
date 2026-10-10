#include "types.h"
struct func_005FAC20_a0 {
    char pad0[0x3440];
    s32 unk3440;
};

extern "C" void func_005FAC20(struct func_005FAC20_a0 *a0, s32 a1) {
    a0->unk3440 = a1;
}
