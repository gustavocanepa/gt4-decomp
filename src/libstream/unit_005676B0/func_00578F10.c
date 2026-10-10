#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00574D78(s32);                         /* extern */
s32 func_0057CA20();                            /* extern */

extern char D_00689EB0[];
struct func_00578F10_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_00578F10(void *arg0) {
    func_0057CA20();
    ((struct func_00578F10_arg0 *)arg0)->unk8 = (s32)D_00689EB0;
    func_00574D78(arg0 + 0xC);
}
