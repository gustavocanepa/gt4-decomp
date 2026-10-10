#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00101030();                            /* extern */
s32 func_00109630(void *, s32);             /* extern */
s32 func_00574D78(s32);                         /* extern */

extern char D_0065A050[];
struct func_0010AA50_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x34];
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
};

void func_0010AA50(void *arg0) {
    func_00101030();
    ((struct func_0010AA50_arg0 *)arg0)->unk64 = (s32)D_0065A050;
    func_00574D78(arg0 + 0x6C);
    ((struct func_0010AA50_arg0 *)arg0)->unk9C = 0;
    ((struct func_0010AA50_arg0 *)arg0)->unkA0 = 0;
    ((struct func_0010AA50_arg0 *)arg0)->unkA4 = 0;
    func_00109630(arg0 + 0x44, 0x2710);
}
