#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00512020_arg1 {
    char pad0[0x4];
    void *unk4;
    void *unk8;
};
struct func_00512020_arg0 {
    s32 unk0;
    void *unk4;
};
struct func_00512020_temp_v1 {
    char pad0[0x8];
    void *unk8;
};
struct func_00512020_temp_v1_2 {
    char pad0[0x4];
    void *unk4;
};

s32 func_00512020(struct func_00512020_arg0 *arg0, struct func_00512020_arg1 *arg1) {
    struct func_00512020_temp_v1 *temp_v1;
    struct func_00512020_temp_v1_2 *temp_v1_2;

    temp_v1 = arg1->unk4;
    arg0->unk0 = (s32) (arg0->unk0 - 1);
    if (temp_v1 != NULL) {
        temp_v1->unk8 = (void *) arg1->unk8;
    } else {
        arg0->unk4 = (void *) arg1->unk8;
    }
    temp_v1_2 = arg1->unk8;
    if (temp_v1_2 != NULL) {
        temp_v1_2->unk4 = (void *) arg1->unk4;
    }
    return 0;
}
