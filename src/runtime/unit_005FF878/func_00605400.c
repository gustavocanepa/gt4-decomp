#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00605400_arg0 {
    char pad0[0xC];
    s32 unkC;
};

u8 func_00605400(struct func_00605400_arg0 *arg0, s32 arg1) {
    return *(s32 *)(arg0->unkC + arg1);
}
