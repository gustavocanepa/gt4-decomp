#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002B4E78();                            /* extern */
s32 func_002B4F40(void *, s32, s32);            /* extern */
s32 func_005769F0(s32);                     /* extern */
s32 func_00576A28(s32);                     /* extern */

extern char D_008381C8[];
struct func_002B50F8_arg0 {
    char pad0[0xBC];
    s32 unkBC;
};

void func_002B50F8(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_s1;

    if (arg2 != 0) {
        func_002B4E78();
    }
    func_005769F0((s32)D_008381C8);
    temp_s1 = ((struct func_002B50F8_arg0 *)arg0)->unkBC;
    ((struct func_002B50F8_arg0 *)arg0)->unkBC = arg2;
    func_00576A28((s32)D_008381C8);
    if (temp_s1 != 0) {
        func_002B4F40(arg0, arg1, temp_s1);
    }
}
