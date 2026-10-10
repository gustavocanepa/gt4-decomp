#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CCC28_arg0_unk10 {
    char pad0[0x1144];
    s32 unk1144;
};
struct func_005CCC28_arg0 {
    char pad0[0x10];
    struct func_005CCC28_arg0_unk10 *unk10;
};

void func_005CCC28(struct func_005CCC28_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1144 = arg1;
}
