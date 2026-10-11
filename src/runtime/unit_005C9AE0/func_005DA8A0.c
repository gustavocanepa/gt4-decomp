#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00574D78(s32);                         /* extern */
s32 func_005DAA98();                            /* extern */

extern char D_00664B88[];
struct func_005DA8A0_arg0 {
    char pad0[0x10C];
    s32 unk10C;
};

void func_005DA8A0(void *arg0) {
    func_005DAA98();
    ((struct func_005DA8A0_arg0 *)arg0)->unk10C = (s32)D_00664B88;
    func_00574D78(arg0 + 0x110);
}
