#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00101030();                            /* extern */
s32 func_00229540(s32);                         /* extern */
s32 func_00574D78(void *);                      /* extern */

extern char D_00659FB8[];
struct func_00109A78_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x8];
    s32 unk70;
};

void func_00109A78(void *arg0) {
    func_00101030();
    ((struct func_00109A78_arg0 *)arg0)->unk64 = (s32)D_00659FB8;
    func_00229540(arg0 + 0x6C);
    ((struct func_00109A78_arg0 *)arg0)->unk70 = 0;
    func_00574D78(arg0 + 0x74);
}
