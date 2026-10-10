#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CC840_arg0_unk10 {
    char pad0[0x1134];
    s32 unk1134;
};
struct func_005CC840_arg0 {
    char pad0[0x10];
    struct func_005CC840_arg0_unk10 *unk10;
};

void func_005CC840(struct func_005CC840_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1134 = arg1;
}
