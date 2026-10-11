#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00556450(void *, s32);                     /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_006899C0[];
struct func_00610F08_arg0 {
    char pad0[0x60];
    s32 unk60;
};

void func_00610F08(struct func_00610F08_arg0 *arg0, s32 arg1) {
    arg0->unk60 = (s32)D_006899C0;
    func_00556450(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
