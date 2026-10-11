#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3E18_arg0 {
    char pad0[0xE334];
    s32 unkE334;
};

void func_005F3E18(struct func_005F3E18_arg0 *arg0, s32 arg1) {
    arg0->unkE334 = arg1;
}
