#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00605450_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

u8 func_00605450(struct func_00605450_arg0 *arg0, s32 arg1) {
    return *(s32 *)(arg0->unk1C + arg1);
}
