#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CCC68_arg0_unk10 {
    char pad0[0x1170];
    s32 unk1170;
};
struct func_005CCC68_arg0 {
    char pad0[0x10];
    struct func_005CCC68_arg0_unk10 *unk10;
};

void func_005CCC68(struct func_005CCC68_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1170 = arg1;
}
