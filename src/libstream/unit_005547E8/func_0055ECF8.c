#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0055F9F8();                            /* extern */
s32 func_006122C8(s32);                         /* extern */

extern char D_00689B28[];
struct func_0055ECF8_arg0 {
    char pad0[0x3C];
    s32 unk3C;
    char pad40[0xC];
    s32 unk4C;
    s32 unk50;
};

s32 func_0055ECF8(void *arg0) {
    func_0055F9F8();
    ((struct func_0055ECF8_arg0 *)arg0)->unk3C = (s32)D_00689B28;
    func_006122C8(arg0 + 0x40);
    ((struct func_0055ECF8_arg0 *)arg0)->unk4C = 2;
    ((struct func_0055ECF8_arg0 *)arg0)->unk50 = 0;
}
