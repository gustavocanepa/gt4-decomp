#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FE5A0_arg0 {
    char pad0[0xF0FC];
    s32 unkF0FC;
};

void func_005FE5A0(struct func_005FE5A0_arg0 *arg0, s32 arg1) {
    arg0->unkF0FC = arg1;
}
