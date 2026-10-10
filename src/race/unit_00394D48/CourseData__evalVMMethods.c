#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 ModelSet2__evalHostMethod(void *, s32, s32);        /* extern */

struct func_00397638_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0xC];
    void *unk14;
    char pad18[0xC];
    void *unk24;
    char pad28[0x2C];
    void *unk54;
    void *unk58;
};
struct func_00397638_temp_a0 {
    char pad0[0x7C];
    s32 unk7C;
};
struct func_00397638_temp_a0_2 {
    char pad0[0x7C];
    s32 unk7C;
};
struct func_00397638_temp_a0_3 {
    char pad0[0x7C];
    s32 unk7C;
};
struct func_00397638_temp_a0_4 {
    char pad0[0x7C];
    s32 unk7C;
};
struct func_00397638_temp_a0_5 {
    char pad0[0x7C];
    s32 unk7C;
};

s32 CourseData__evalVMMethods(struct func_00397638_arg0 *arg0) {
    struct func_00397638_temp_a0 *temp_a0;
    struct func_00397638_temp_a0_2 *temp_a0_2;
    struct func_00397638_temp_a0_3 *temp_a0_3;
    struct func_00397638_temp_a0_4 *temp_a0_4;
    struct func_00397638_temp_a0_5 *temp_a0_5;

    temp_a0 = arg0->unk4;
    if (temp_a0 != NULL) {
        ModelSet2__evalHostMethod(temp_a0, temp_a0->unk7C, 0);
    }
    temp_a0_2 = arg0->unk54;
    if (temp_a0_2 != NULL) {
        ModelSet2__evalHostMethod(temp_a0_2, temp_a0_2->unk7C, 0);
    }
    temp_a0_3 = arg0->unk58;
    if (temp_a0_3 != NULL) {
        ModelSet2__evalHostMethod(temp_a0_3, temp_a0_3->unk7C, 0);
    }
    temp_a0_4 = arg0->unk14;
    if (temp_a0_4 != NULL) {
        ModelSet2__evalHostMethod(temp_a0_4, temp_a0_4->unk7C, 0);
    }
    temp_a0_5 = arg0->unk24;
    if (temp_a0_5 != NULL) {
        ModelSet2__evalHostMethod(temp_a0_5, temp_a0_5->unk7C, 0);
    }
}
