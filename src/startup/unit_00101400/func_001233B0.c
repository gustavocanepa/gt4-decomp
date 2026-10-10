#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00574EB0(void *);                      /* extern */

struct func_001233B0_arg0 {
    char pad0[0x2A4];
    s32 unk2A4;
};

s32 func_001233B0(void *arg0) {
    if (((struct func_001233B0_arg0 *)arg0)->unk2A4 != 0) {
        ((struct func_001233B0_arg0 *)arg0)->unk2A4 = 0;
        func_00574EB0(arg0 + 0x18);
    }
}
