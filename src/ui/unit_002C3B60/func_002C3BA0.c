#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002C3DB8();                            /* extern */
s32 func_00460858(s32);                         /* extern */

struct func_002C3BA0_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_002C3BA0(struct func_002C3BA0_arg0 *arg0) {
    if (arg0->unk10 != 0) {
        func_002C3DB8();
        func_00460858(arg0->unk10);
        arg0->unk10 = 0;
    }
}
