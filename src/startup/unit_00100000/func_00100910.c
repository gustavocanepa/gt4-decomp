#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00101030();                            /* extern */
s32 func_00574D78(s32);                         /* extern */

extern char D_00659A28[];
struct func_00100910_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x34];
    s32 unk9C;
};

void func_00100910(void *arg0) {
    func_00101030();
    ((struct func_00100910_arg0 *)arg0)->unk64 = (s32)D_00659A28;
    func_00574D78(arg0 + 0x6C);
    ((struct func_00100910_arg0 *)arg0)->unk9C = 0;
}
