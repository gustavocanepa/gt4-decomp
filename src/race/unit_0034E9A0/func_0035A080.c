#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

u8 *func_00359510(void);
struct func_0035A080_arg0 {
    char pad0[0x32];
    u8 unk32;
};

s32 func_0035A080(struct func_0035A080_arg0 *arg0) {
    if (*func_00359510() == 1) return 1;
    return arg0->unk32 == 6;
}
