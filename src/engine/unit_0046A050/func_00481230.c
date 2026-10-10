#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00481280(void *, s32);
struct func_00481230_arg0 {
    char pad0[0x10];
    void *unk10;
};

s32 func_00481230(struct func_00481230_arg0 *arg0, s32 arg1) {
    s32 r;
    void *n;
    for (;;) {
        r = func_00481280(arg0, arg1);
        if (r != 0) break;
        n = arg0->unk10;
        arg0 = n;
        if (n == NULL) break;
    }
    return r;
}
