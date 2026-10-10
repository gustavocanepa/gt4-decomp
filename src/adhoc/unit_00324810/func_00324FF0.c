#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00619E68[];
struct func_00324FF0_arg0 {
    u8 pad0[0xC];
    void *unkC;
};

s32 func_00324FF0(struct func_00324FF0_arg0 *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)D_00619E68;
    if (arg0 != NULL) {
        arg0->unkC = temp_v0;
        *(void **)D_00619E68 = arg0;
    }
    return (s32) temp_v0;
}
