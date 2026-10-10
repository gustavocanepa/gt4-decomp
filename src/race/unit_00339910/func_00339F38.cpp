#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_00339C08(s32, void *, f32);            /* extern */
s32 func_003E91E0(s32, s32, s32);               /* extern */
s32 func_00459E30(s32, s32, f32);               /* extern */
s32 func_0045B4D8(void *, s32, s32);        /* extern */
s32 func_0045B548(void *, s32);                 /* extern */

extern char D_0069F2F0[];
struct func_00339F38_arg1 {
    char pad0[0x14];
    s32 unk14;
};

void func_00339F38(s32 arg0, char *arg1, s32 arg2, s32 arg3, f32 fparg0) {
    s8 sp[0x10];
    func_0045B4D8(sp, arg0, (s32)D_0069F2F0);
    func_00459E30(arg0, (s32)(arg1 + 0x2890), fparg0);
    func_00339C08(arg0, arg1, fparg0);
    if (arg3 != 0) {
        func_003E91E0(arg2 + 0x31D0, arg0, ((struct func_00339F38_arg1 *)arg1)->unk14);
    }
    func_0045B548(sp, arg0);
}

}
