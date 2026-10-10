#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0060AD80_arg0 {
    char pad0[0x80];
    s32 unk80;
};

s32 func_0060AD80(struct func_0060AD80_arg0 *arg0) {
    return arg0->unk80 == 3;
}
