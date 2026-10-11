#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3E58_arg0 {
    char pad0[0xE348];
    s32 unkE348;
};

void func_005F3E58(struct func_005F3E58_arg0 *arg0, s32 arg1) {
    arg0->unkE348 = arg1;
}
