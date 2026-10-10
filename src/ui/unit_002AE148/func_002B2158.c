#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0025B370(s32);                         /* extern */
s32 func_0025B3D0(s32);                         /* extern */

struct func_002B2158_arg0 {
    char pad0[0xB0];
    s32 unkB0;
    char padB4[0x68];
    s32 unk11C;
};

void func_002B2158(struct func_002B2158_arg0 *arg0) {
    s32 temp_a0;

    temp_a0 = arg0->unk11C;
    if (arg0->unkB0 == 0) {
        func_0025B3D0(temp_a0);
        return;
    }
    func_0025B370(temp_a0);
}
