#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004FF5B0_arg0 {
    s32 unk0;
    void *unk4;
};
struct func_004FF5B0_temp_v1 {
    s32 unk0;
    s32 unk4;
};

void func_004FF5B0(struct func_004FF5B0_arg0 *arg0) {
    struct func_004FF5B0_temp_v1 *temp_v1;

    temp_v1 = arg0->unk4;
    if (arg0->unk0 == 0) {
        temp_v1->unk0 = 1;
        return;
    }
    temp_v1->unk4 = 1;
}
