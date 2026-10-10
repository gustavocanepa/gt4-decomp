#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0046C1C0_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_0046C1C0(struct func_0046C1C0_arg0 *arg0) {
    s32 temp_v1;
    s32 var_a2;

    temp_v1 = arg0->unkC;
    var_a2 = 0;
    switch (temp_v1) {                              /* irregular */
    case 1:
        var_a2 = 2;
        break;
    case 3:
        var_a2 = 4;
        break;
    case 2:
        var_a2 = 3;
        break;
    }
    arg0->unk8 = var_a2;
    arg0->unk4 = 3;
}
