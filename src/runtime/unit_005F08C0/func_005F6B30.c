#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F6B30_arg0 {
    char pad0[0xE408];
    s32 unkE408;
};

void func_005F6B30(struct func_005F6B30_arg0 *arg0, s32 arg1) {
    arg0->unkE408 = arg1;
}
