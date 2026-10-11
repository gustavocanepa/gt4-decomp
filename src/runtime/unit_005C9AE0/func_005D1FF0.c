#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001CBFE0();                            /* extern */
s32 func_001D11D0(void *, s32);             /* extern */

extern char D_00661B70[];
struct func_005D1FF0_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    s32 unk50;
};

void func_005D1FF0(struct func_005D1FF0_arg0 *arg0) {
    func_001CBFE0();
    arg0->unk50 = 0;
    arg0->unk4C = (s32)D_00661B70;
    func_001D11D0(arg0, 0);
}
