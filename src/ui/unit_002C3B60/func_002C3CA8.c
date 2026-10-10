#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002C3DB8();                            /* extern */
s32 func_004608C8(s32, s32, void *);                /* extern */

struct func_002C3CA8_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

void func_002C3CA8(void *arg0, s32 arg1) {
    if (((struct func_002C3CA8_arg0 *)arg0)->unk10 != 0) {
        func_002C3DB8();
        ((struct func_002C3CA8_arg0 *)arg0)->unk14 = func_004608C8(((struct func_002C3CA8_arg0 *)arg0)->unk10, arg1, arg0 + 0x18);
    }
}
