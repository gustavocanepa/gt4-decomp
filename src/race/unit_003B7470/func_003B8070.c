#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00105280(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_0067FC58[];
struct func_003B8070_arg0 {
    char pad0[0x2428];
    s32 unk2428;
};

void func_003B8070(void *arg0, s32 arg1) {
    ((struct func_003B8070_arg0 *)arg0)->unk2428 = (s32)D_0067FC58;
    func_00105280(arg0 + 0xC8, 2);
    func_00105280(arg0 + 0x8C, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
