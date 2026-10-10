#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005E8AD8_arg0 {
    char pad0[0x308];
    s32 unk308;
};

s32 func_005E8AD8(struct func_005E8AD8_arg0 *arg0) {
    return arg0->unk308 & 1;
}
