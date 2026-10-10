#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005E44C8_arg0 {
    char pad0[0x24];
    s32 unk24;
};

s32 func_005E44C8(struct func_005E44C8_arg0 *arg0) {
    return arg0->unk24 & 0xF;
}
