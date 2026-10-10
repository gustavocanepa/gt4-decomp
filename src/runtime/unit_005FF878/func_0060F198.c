#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00576090(s32);                         /* extern */
s32 func_0060F418();                            /* extern */

extern char D_006896F8[];
struct func_0060F198_arg0 {
    char pad0[0x40C];
    s32 unk40C;
};

void func_0060F198(void *arg0) {
    func_0060F418();
    ((struct func_0060F198_arg0 *)arg0)->unk40C = (s32)D_006896F8;
    func_00576090(arg0 + 0x410);
}
