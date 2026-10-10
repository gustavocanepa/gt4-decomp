#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F3AB8_arg0 {
    char pad0[0x34];
    s32 unk34;
};

void func_005F3AB8(struct func_005F3AB8_arg0 *arg0) {
    arg0->unk34 = (s32) (arg0->unk34 ^ 1);
}
