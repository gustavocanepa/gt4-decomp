#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CC860_arg0_unk10 {
    char pad0[0x1138];
    s32 unk1138;
};
struct func_005CC860_arg0 {
    char pad0[0x10];
    struct func_005CC860_arg0_unk10 *unk10;
};

void func_005CC860(struct func_005CC860_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1138 = arg1;
}
