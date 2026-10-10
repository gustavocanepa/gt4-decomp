#include "types.h"
struct func_005FB330_a0 {
    char pad0[0x11E8];
    s32 unk11E8;
};

extern "C" void func_005FB330(struct func_005FB330_a0 *a0, s32 a1) {
    a0->unk11E8 = a1;
}
