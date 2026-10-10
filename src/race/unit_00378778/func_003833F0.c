#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_003833F0_arg0 {
    char pad0[0x180];
    s32 unk180;
};

s32 func_003833F0(struct func_003833F0_arg0 *arg0, s32 arg1, s32 arg2) {
    return arg2 != arg0->unk180;
}
