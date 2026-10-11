#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F4F20_arg0 {
    char pad0[0xF8A0];
    s32 unkF8A0;
};

void func_005F4F20(struct func_005F4F20_arg0 *arg0, s32 arg1) {
    arg0->unkF8A0 = arg1;
}
