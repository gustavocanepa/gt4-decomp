#include "types.h"
struct func_00601B80_a0 {
    char pad0[0x110C];
    s32 unk110C;
};

extern "C" s32 func_00601B80(struct func_00601B80_a0 *a0) {
    return a0->unk110C;
}
