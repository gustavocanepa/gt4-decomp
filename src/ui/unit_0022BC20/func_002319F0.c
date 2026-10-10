#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002319E0(void *);
struct func_002319F0_arg0 {
    char pad0[0x6CC];
    s32 unk6CC;
};

s32 func_002319F0(struct func_002319F0_arg0 *arg0) {
    s32 var_v0;
    var_v0 = 0;
    if (func_002319E0(arg0) != 0) {
        s32 n = 0; if (arg0->unk6CC < 0) n = 1; var_v0 = n == 0;
    }
    return var_v0;
}
