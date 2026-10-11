#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CC4B8_arg0_unk10 {
    char pad0[0x10E8];
    s32 unk10E8;
};
struct func_005CC4B8_arg0 {
    char pad0[0x10];
    struct func_005CC4B8_arg0_unk10 *unk10;
};

void func_005CC4B8(struct func_005CC4B8_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk10E8 = arg1;
}
