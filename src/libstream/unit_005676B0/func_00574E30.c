#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005767E0();                            /* extern */

struct func_00574E30_arg0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
};

void func_00574E30(struct func_00574E30_arg0 *arg0) {
    if (arg0->unk2C != 0) {
        arg0->unk2C = 0;
        return;
    }
    arg0->unk28 = 1;
    func_005767E0();
    arg0->unk28 = 0;
}
