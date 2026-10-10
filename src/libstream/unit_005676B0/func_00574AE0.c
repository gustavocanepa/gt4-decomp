#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00572CD8();                            /* extern */

extern char D_00689D40[];
struct func_00574AE0_arg0 {
    char pad0[0x28];
    s32 unk28;
    char pad2C[0x18];
    s32 unk44;
};

s32 func_00574AE0(void *arg0) {
    func_00572CD8();
    ((struct func_00574AE0_arg0 *)arg0)->unk28 = (s32) (arg0 + 0x48);
    ((struct func_00574AE0_arg0 *)arg0)->unk44 = (s32)D_00689D40;
}
