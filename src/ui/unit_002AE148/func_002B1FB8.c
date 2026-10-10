#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0025B370();                            /* extern */
s32 func_0025B3D0();                            /* extern */

struct func_002B1FB8_arg0 {
    char pad0[0xB0];
    s32 unkB0;
};

void func_002B1FB8(struct func_002B1FB8_arg0 *arg0) {
    if (arg0->unkB0 == 0) {
        func_0025B3D0();
        return;
    }
    func_0025B370();
}
