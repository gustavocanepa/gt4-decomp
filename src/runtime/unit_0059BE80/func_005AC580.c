#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005AC580_arg1 {
    void *unk0;
    s32 unk4;
};
struct func_005AC580_arg0 {
    char pad0[0x4C];
    s32 unk4C;
};

void func_005AC580(struct func_005AC580_arg0 *arg0, struct func_005AC580_arg1 *arg1) {
    void **temp_v0;

    if (arg1 != NULL) {
        temp_v0 = (arg1->unk4 * 4) + arg0->unk4C;
        arg1->unk0 = (void *) *temp_v0;
        *temp_v0 = arg1;
    }
}
