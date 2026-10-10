#include "types.h"
struct func_00600C80_a0 {
    char pad0[0x29];
    u8 unk29;
};

extern "C" u8 func_00600C80(struct func_00600C80_a0 *a0) {
    return a0->unk29;
}
