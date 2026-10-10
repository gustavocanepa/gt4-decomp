#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00574D78();                            /* extern */

struct func_005787A0_arg0 {
    char pad0[0x30];
    s32 unk30;
};

void func_005787A0(struct func_005787A0_arg0 *arg0) {
    func_00574D78();
    arg0->unk30 = -1;
}
