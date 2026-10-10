#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CC4D8_arg0_unk10 {
    char pad0[0x10EC];
    s32 unk10EC;
};
struct func_005CC4D8_arg0 {
    char pad0[0x10];
    struct func_005CC4D8_arg0_unk10 *unk10;
};

void func_005CC4D8(struct func_005CC4D8_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk10EC = arg1;
}
