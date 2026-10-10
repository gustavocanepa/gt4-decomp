#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_00574E78(s32);                         /* extern */
s32 func_00574EE8(void *);                      /* extern */

struct func_00123368_arg0 {
    char pad0[0x2A4];
    s32 unk2A4;
    s32 unk2A8;
    s32 unk2AC;
    s32 unk2B0;
};

void func_00123368(char *arg0) {
    ((struct func_00123368_arg0 *)arg0)->unk2A4 = 1;
    ((struct func_00123368_arg0 *)arg0)->unk2A8 = 0;
    ((struct func_00123368_arg0 *)arg0)->unk2AC = 0;
    ((struct func_00123368_arg0 *)arg0)->unk2B0 = 0;
    func_00574E78((s32)(arg0 + 0x18));
    func_00574EE8(arg0 + 0x48);
}

}
