#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_0025B500(s32, s32, void *, void *, s32); /* extern */

struct func_002C16E0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_002C16E0(char *arg0, s32 arg1) {
    ((struct func_002C16E0_arg0 *)arg0)->unk14 = arg1;
    func_0025B500(arg1, (s32)(arg0 + 0x18), arg0 + 0x1C, arg0 + 0x20, (s32)(arg0 + 0x24));
}

}
