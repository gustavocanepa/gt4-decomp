#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"


struct func_00328C08_arg1 {
    u8 pad0[0x4];
    void *unk4;
    void *unk8;
};
struct func_00328C08_temp_v1 {
    u8 pad0[0x8];
    void *unk8;
};
struct func_00328C08_arg0 {
    u8 pad0[0x30];
    void *unk30;
    void *unk34;
};

void func_00328C08(struct func_00328C08_arg0 *arg0, struct func_00328C08_arg1 *arg1) {
    struct func_00328C08_temp_v1 *temp_v1;

    temp_v1 = arg1->unk4;
    if (temp_v1 != NULL) {
        temp_v1->unk8 = (void *) arg1->unk8;
    }
    if (arg1->unk8 != NULL) {
        M2C_FIELD(arg1->unk8, void **, 4) = arg1->unk4;
    }
    if (arg1->unk4 == NULL) {
        arg0->unk30 = arg1->unk8;
    }
    if (arg1->unk8 == NULL) {
        arg0->unk34 = (void *) arg1->unk4;
    }
    arg1->unk4 = NULL;
    arg1->unk8 = NULL;
}
