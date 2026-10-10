#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0020C300_arg0 {
    char pad0[0x34];
    s32 unk34;
    char pad38[0x4];
    s32 unk3C;
};

void func_0020C300(struct func_0020C300_arg0 *arg0, s32 arg1) {
    arg0->unk34 = arg1;
    arg0->unk3C = 0;
}
