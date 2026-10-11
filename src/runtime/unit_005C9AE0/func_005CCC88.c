#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CCC88_arg0_unk10 {
    char pad0[0x1174];
    s32 unk1174;
};
struct func_005CCC88_arg0 {
    char pad0[0x10];
    struct func_005CCC88_arg0_unk10 *unk10;
};

void func_005CCC88(struct func_005CCC88_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1174 = arg1;
}
