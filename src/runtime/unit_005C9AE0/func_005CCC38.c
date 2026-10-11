#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CCC38_arg0_unk10 {
    char pad0[0x1148];
    s32 unk1148;
};
struct func_005CCC38_arg0 {
    char pad0[0x10];
    struct func_005CCC38_arg0_unk10 *unk10;
};

s32 func_005CCC38(struct func_005CCC38_arg0 *arg0) {
    return arg0->unk10->unk1148;
}
