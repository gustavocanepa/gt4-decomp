#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576090(s32);                         /* extern */
s32 func_0060F4B8();                            /* extern */

extern char D_00689698[];
struct func_0060F2D8_arg0 {
    char pad0[0x4C];
    s32 unk4C;
};

void func_0060F2D8(void *arg0) {
    func_0060F4B8();
    ((struct func_0060F2D8_arg0 *)arg0)->unk4C = (s32)D_00689698;
    func_00576090(arg0 + 0x50);
}
