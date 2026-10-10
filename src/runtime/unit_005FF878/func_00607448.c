#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00575DA0(void *);                      /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688A20[];
struct func_00607448_arg0 {
    char pad0[0x54];
    s32 unk54;
    char pad58[0x4];
    s32 unk5C;
};
struct func_00607448_temp_v1 {
    char pad0[0x8];
    s32 unk8;
};

void func_00607448(struct func_00607448_arg0 *arg0, s32 arg1) {
    s32 temp_v0;
    struct func_00607448_temp_v1 *temp_v1;

    arg0->unk5C = (s32)D_00688A20;
    temp_v1 = arg0->unk54 - 0x10;
    temp_v0 = temp_v1->unk8 - 1;
    temp_v1->unk8 = temp_v0;
    if (temp_v0 == 0) {
        func_00575DA0(temp_v1);
    }
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
