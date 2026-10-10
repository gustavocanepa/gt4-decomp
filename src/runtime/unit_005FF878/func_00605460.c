#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00605460_arg0 {
    char pad0[0x18];
    s32 unk18;
};

u8 func_00605460(struct func_00605460_arg0 *arg0, s32 arg1) {
    return *(s32 *)(arg0->unk18 + arg1);
}
