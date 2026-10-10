#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0025B370();                            /* extern */
s32 func_0025B3D0();                            /* extern */

struct func_002E97B8_arg0 {
    char pad0[0xC4];
    s32 unkC4;
};

void func_002E97B8(struct func_002E97B8_arg0 *arg0) {
    if (arg0->unkC4 != 0) {
        func_0025B3D0();
        return;
    }
    func_0025B370();
}
