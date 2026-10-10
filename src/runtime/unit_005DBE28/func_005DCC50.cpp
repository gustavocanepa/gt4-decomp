#include "types.h"
struct func_005DCC50_a0 {
    char pad0[0x10C];
    s32 unk10C;
};

extern "C" void func_005DCC50(struct func_005DCC50_a0 *a0, s32 a1) {
    a0->unk10C = a1;
}
