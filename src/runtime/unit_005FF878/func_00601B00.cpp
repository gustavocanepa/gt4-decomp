#include "types.h"
struct func_00601B00_a0 {
    char pad0[0x10EC];
    s32 unk10EC;
};

extern "C" s32 func_00601B00(struct func_00601B00_a0 *a0) {
    return a0->unk10EC;
}
