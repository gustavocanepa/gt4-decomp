#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00574D78();                            /* extern */
s32 func_006122C8(void *);                      /* extern */

extern char D_00689B88[];
struct func_0055F9F8_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

void func_0055F9F8(void *arg0) {
    ((struct func_0055F9F8_arg0 *)arg0)->unk3C = (s32)D_00689B88;
    func_00574D78();
    func_006122C8(arg0 + 0x30);
}
