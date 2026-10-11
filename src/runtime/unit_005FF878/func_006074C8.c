#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006074C8_arg0 {
    char pad0[0x4];
    void *unk4;
};
struct func_006074C8_temp_v1 {
    char pad0[0x2];
    s16 unk2;
    s16 unk4;
};

s32 func_006074C8(struct func_006074C8_arg0 *arg0, s32 arg1) {
    s32 var_a0;
    struct func_006074C8_temp_v1 *temp_v1;

    temp_v1 = arg0->unk4;
    var_a0 = 0;
    if (arg1 >= temp_v1->unk2) {
        var_a0 = arg1 < temp_v1->unk4;
    }
    return var_a0;
}
