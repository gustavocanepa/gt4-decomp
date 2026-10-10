#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0046C218_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    char padC[0x864];
    s32 unk870;
};

void func_0046C218(struct func_0046C218_arg0 *arg0) {
    s32 temp_v1;
    s32 var_a1;

    temp_v1 = arg0->unk870;
    var_a1 = 0;
    switch (temp_v1) {                              /* irregular */
    case 2:
        var_a1 = 3;
        break;
    case 1:
        var_a1 = 5;
        break;
    }
    arg0->unk8 = var_a1;
    arg0->unk4 = 3;
}
