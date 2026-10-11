#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0044A670(void *, s32);             /* extern */
s32 free(s32);                         /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_006882F0[];
struct func_00448F78_arg0 {
    s32 unk0;
    char pad4[0x64];
    s32 unk68;
};

void func_00448F78(void *arg0, s32 arg1) {
    s32 temp_v1;

    ((struct func_00448F78_arg0 *)arg0)->unk68 = (s32)D_006882F0;
    temp_v1 = ((struct func_00448F78_arg0 *)arg0)->unk0;
    if (temp_v1 != 0) {
        free(temp_v1);
    }
    func_0044A670(arg0 + 0x24, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
