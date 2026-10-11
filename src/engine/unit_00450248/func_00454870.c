#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00454870_arg0 {
    char pad0[0x24];
    u16 unk24;
};

void func_00454870(struct func_00454870_arg0 *arg0) {
    u16 temp_v1;
    u32 var_a0;

    temp_v1 = arg0->unk24;
    var_a0 = 0;
    if (temp_v1 != 0) {
        do {
            var_a0 += 1;
        } while (var_a0 < temp_v1);
    }
}
