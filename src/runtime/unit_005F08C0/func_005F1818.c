#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

char * func_005C2560(void *);
struct func_005F1818_arg1 {
    char pad0[0x8];
    s8 *unk8;
};
struct func_005F1818_temp_a1 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

s8 **func_005F1818(s8 **arg0, struct func_005F1818_arg1 *arg1) {
    s8 *temp_v0;
    s8 *var_a2;
    struct func_005F1818_temp_a1 *temp_a1;

    temp_v0 = arg1->unk8;
    temp_a1 = temp_v0 - 0x10;
    var_a2 = temp_v0;
    if (temp_a1->unkC != 0) {
        var_a2 = func_005C2560(temp_a1);
    } else {
        temp_a1->unk8 = (s32) (temp_a1->unk8 + 1);
    }
    *arg0 = var_a2;
    return arg0;
}
