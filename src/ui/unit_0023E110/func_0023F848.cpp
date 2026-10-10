#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0023F890();                            /* extern */
s32 func_002C3B60(s32, s32);                    /* extern */
s32 func_00460B70();                            /* extern */

struct func_0023F848_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0023F848(void *arg0, s32 arg1) {
    func_0023F890();
    func_00460B70();
    func_002C3B60(((struct func_0023F848_arg0 *)arg0)->unk10, arg1);
}
