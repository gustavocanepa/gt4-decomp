#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005F0498_arg0 {
    char pad0[0x24];
    void *unk24;
    s32 unk28;
};
struct func_005F0498_temp_v0 {
    char pad0[0x30];
    s32 unk30;
};

void func_005F0498(struct func_005F0498_arg0 *arg0, s32 arg1) {
    s32 var_v0;
    struct func_005F0498_temp_v0 *temp_v0;

    temp_v0 = arg0->unk24;
    if (temp_v0 != NULL) {
        var_v0 = temp_v0->unk30 + (arg1 * 4);
    } else {
        var_v0 = 0;
    }
    arg0->unk28 = var_v0;
}
