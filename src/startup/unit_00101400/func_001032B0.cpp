#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_00574EE8(s32);                         /* extern */
s32 func_00578908(s32);                         /* extern */
s32 func_00578AF0(s32);                         /* extern */

struct func_001032B0_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_001032B0(char *arg0) {
    ((struct func_001032B0_arg0 *)arg0)->unk4 = 0;
    func_00574EE8((s32)(arg0 + 8));
    func_00578908(((struct func_001032B0_arg0 *)arg0)->unk0);
    func_00578AF0(((struct func_001032B0_arg0 *)arg0)->unk0);
}

}
