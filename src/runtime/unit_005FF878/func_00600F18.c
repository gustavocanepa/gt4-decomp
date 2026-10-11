#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00600F18_arg0 {
    char pad0[0xA58];
    s32 unkA58;
};

void func_00600F18(struct func_00600F18_arg0 *arg0) {
    arg0->unkA58 = 1;
}
