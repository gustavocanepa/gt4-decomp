#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GranTurismo4__GameObjectBase__sync();                            /* extern */
s32 func_00574DA8(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00659F18[];
struct func_001096D8_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void func_001096D8(struct func_001096D8_arg0 *arg0, s32 arg1) {
    arg0->unk64 = (s32)D_00659F18;
    GranTurismo4__GameObjectBase__sync();
    func_00574DA8(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
