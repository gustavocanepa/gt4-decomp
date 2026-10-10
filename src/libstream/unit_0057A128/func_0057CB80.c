#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0057CB80_arg1 {
    char pad0[0x4];
    void *unk4;
    void *unk8;
};
struct func_0057CB80_temp_v1 {
    char pad0[0x8];
    void *unk8;
};
struct func_0057CB80_arg0 {
    void *unk0;
    void *unk4;
};
struct func_0057CB80_temp_v0 {
    char pad0[0x4];
    void *unk4;
};

void func_0057CB80(struct func_0057CB80_arg0 *arg0, struct func_0057CB80_arg1 *arg1) {
    struct func_0057CB80_temp_v0 *temp_v0;
    struct func_0057CB80_temp_v1 *temp_v1;

    temp_v1 = arg1->unk4;
    temp_v0 = arg1->unk8;
    if (temp_v1 != NULL) {
        temp_v1->unk8 = temp_v0;
    } else {
        arg0->unk0 = temp_v0;
    }
    if (temp_v0 != NULL) {
        temp_v0->unk4 = temp_v1;
        return;
    }
    arg0->unk4 = temp_v1;
}
