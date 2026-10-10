#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005A609C(s32);                         /* extern */

extern char D_00661E18[];
struct func_001D1950_arg0 {
    s32 unk0;
    s8 unk4;
    char pad5[0x3F];
    s32 unk44;
};

s32 func_001D1950(void *arg0, s32 arg1, s32 arg2) {
    ((struct func_001D1950_arg0 *)arg0)->unk0 = (s32)D_00661E18;
    if (arg1 != 0) {
        func_005A609C(arg0 + 4);
    } else {
        ((struct func_001D1950_arg0 *)arg0)->unk4 = 0;
    }
    ((struct func_001D1950_arg0 *)arg0)->unk44 = arg2;
}
