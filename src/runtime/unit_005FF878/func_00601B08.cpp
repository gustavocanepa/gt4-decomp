#include "types.h"
struct func_00601B08_a0 {
    char pad0[0x10EC];
    s32 unk10EC;
};

extern "C" void func_00601B08(struct func_00601B08_a0 *a0, s32 a1) {
    a0->unk10EC = a1;
}
