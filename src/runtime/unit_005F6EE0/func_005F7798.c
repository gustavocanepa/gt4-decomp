#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F7798_arg0 {
    char pad0[0x58];
    s32 unk58;
};

s32 func_005F7798(struct func_005F7798_arg0 *arg0) {
    return ((s32) arg0->unk58 >> 0xA) & 1;
}
