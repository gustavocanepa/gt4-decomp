#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00623818[];
struct func_0044CF10_arg0 {
    void *unk0;
    void *unk4;
    void *unk8;
};

void func_0044CF10(struct func_0044CF10_arg0 *arg0, void *arg1, void *arg2) {
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
    arg0->unk0 = (void *) *(void **)(s32)D_00623818;
    *(void **)(s32)D_00623818 = arg0;
}
