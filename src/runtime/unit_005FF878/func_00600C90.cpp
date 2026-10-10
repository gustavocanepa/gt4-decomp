#include "types.h"
struct func_00600C90_a0 {
    char pad0[0x2A];
    u8 unk2A;
};

extern "C" u8 func_00600C90(struct func_00600C90_a0 *a0) {
    return a0->unk2A;
}
