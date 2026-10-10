#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0040BA80_var_a0 {
    s32 unk0;
    char pad4[0xC];
    s32 unk10;
    char pad14[0xC];
    s32 unk20;
};

void func_0040BA80(void *arg0) {
    s32 var_v0;
    void *var_a0;

    var_a0 = arg0;
    var_v0 = 3;
    do {
        var_v0 -= 1;
        ((struct func_0040BA80_var_a0 *)var_a0)->unk0 = 0;
        ((struct func_0040BA80_var_a0 *)var_a0)->unk10 = 0;
        ((struct func_0040BA80_var_a0 *)var_a0)->unk20 = 0;
        var_a0 += 4;
    } while (var_v0 >= 0);
}
