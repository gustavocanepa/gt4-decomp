#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0047DBD0_arg0_unk0 {
    char pad0[0x38];
    s32 unk38;
};
struct func_0047DBD0_arg0 {
    struct func_0047DBD0_arg0_unk0 *unk0;
    void *unk4;
};
struct func_0047DBD0_temp_v1 {
    s16 unk0;
    char pad2[0x4];
    s16 unk6;
};

s32 func_0047DBD0(struct func_0047DBD0_arg0 *arg0) {
    struct func_0047DBD0_temp_v1 *temp_v1;

    temp_v1 = arg0->unk4;
    if (temp_v1->unk0 == 0) {
        return arg0->unk0->unk38 + (temp_v1->unk6 * 0x18);
    }
    return 0;
}
