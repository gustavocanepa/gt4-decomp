#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005D13A8_arg0 {
    char pad0[0x48];
    u16 unk48;
};

s32 func_005D13A8(struct func_005D13A8_arg0 *arg0) {
    return arg0->unk48 & 1;
}
