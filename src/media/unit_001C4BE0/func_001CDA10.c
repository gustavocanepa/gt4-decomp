#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001CBFE0();                            /* extern */
s32 func_001CDA48(void *, s32);             /* extern */

extern char D_006613F8[];
struct func_001CDA10_arg0 {
    char pad0[0x4C];
    s32 unk4C;
};

void func_001CDA10(struct func_001CDA10_arg0 *arg0) {
    func_001CBFE0();
    arg0->unk4C = (s32)D_006613F8;
    func_001CDA48(arg0, 0);
}
