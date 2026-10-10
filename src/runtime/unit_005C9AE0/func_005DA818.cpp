#include "types.h"
struct func_005DA818_a0 {
    char pad0[0xFC];
    s32 unkFC;
};

extern "C" void func_005DA818(struct func_005DA818_a0 *a0, s32 a1) {
    a0->unkFC = a1;
}
