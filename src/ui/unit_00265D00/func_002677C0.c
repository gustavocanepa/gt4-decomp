#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002679B0();                            /* extern */

struct func_002677C0_arg0 {
    char pad0[0x68];
    s32 unk68;
    char pad6C[0x2C];
    s32 unk98;
};

s32 func_002677C0(struct func_002677C0_arg0 *arg0) {
    if (arg0->unk98 & 0x200000) {
        func_002679B0();
    }
    return arg0->unk68 != 0;
}
