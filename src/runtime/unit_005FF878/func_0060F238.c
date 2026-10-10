#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576090(s32);                         /* extern */
s32 func_0060F468();                            /* extern */

extern char D_006896C8[];
struct func_0060F238_arg0 {
    char pad0[0x201C];
    s32 unk201C;
};

void func_0060F238(void *arg0) {
    func_0060F468();
    ((struct func_0060F238_arg0 *)arg0)->unk201C = (s32)D_006896C8;
    func_00576090(arg0 + 0x2020);
}
