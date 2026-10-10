#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001CBFE0();                            /* extern */

extern char D_00661C70[];
struct func_005D1EC0_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    s32 unk50;
};

void func_005D1EC0(struct func_005D1EC0_arg0 *arg0) {
    func_001CBFE0();
    arg0->unk50 = 0;
    arg0->unk4C = (s32)D_00661C70;
}
