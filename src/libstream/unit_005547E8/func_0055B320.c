#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0055A790();                            /* extern */
s32 func_0055BDA0(s32);                         /* extern */
s32 func_0055BFE0(void *);                      /* extern */

extern char D_00689A90[];
struct func_0055B320_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void func_0055B320(void *arg0) {
    func_0055A790();
    ((struct func_0055B320_arg0 *)arg0)->unk64 = (s32)D_00689A90;
    func_0055BDA0(arg0 + 0x234);
    func_0055BFE0(arg0 + 0x24C);
}
