#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3E38_arg0 {
    char pad0[0xE338];
    s32 unkE338;
};

void func_005F3E38(struct func_005F3E38_arg0 *arg0, s32 arg1) {
    arg0->unkE338 = arg1;
}
