#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0052F8E0(void *);                      /* extern */

struct func_00534170_arg0 {
    s32 unk0;
    char pad4[0x20];
    s32 unk24;
};

s32 func_00534170(void *arg0) {
    s32 var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        func_005A48D8(arg0, 0, 0x98);
        ((struct func_00534170_arg0 *)arg0)->unk24 = 8;
        func_0052F8E0(arg0 + 0x28);
        ((struct func_00534170_arg0 *)arg0)->unk0 = 1;
        var_v0 = 0;
    }
    return var_v0;
}
