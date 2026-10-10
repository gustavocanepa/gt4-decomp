#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688308[];
struct func_00449828_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_00449828(struct func_00449828_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk8 = (s32)D_00688308;
    temp_v1 = arg0->unk0;
    if (temp_v1 != 0) {
        func_00575DA0(temp_v1);
    }
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
