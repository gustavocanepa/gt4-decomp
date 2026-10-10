#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CC430_arg0_unk10 {
    char pad0[0x10DC];
    s32 unk10DC;
};
struct func_005CC430_arg0 {
    char pad0[0x10];
    struct func_005CC430_arg0_unk10 *unk10;
};

s32 func_005CC430(struct func_005CC430_arg0 *arg0) {
    return arg0->unk10->unk10DC != 0;
}
