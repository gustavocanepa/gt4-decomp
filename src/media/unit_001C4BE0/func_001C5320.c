#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_001C5250();                            /* extern */
s32 func_0058C3F0(s32);                             /* extern */

struct func_001C5320_arg0 {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x268];
    s32 unk27C;
};

void func_001C5320(struct func_001C5320_arg0 *arg0) {
    func_001C5250();
    if ((arg0->unk27C == 0x12) && (func_0058C3F0(arg0->unk10) == 0)) {
        arg0->unk27C = (s32) (arg0->unk27C + 1);
    }
}
