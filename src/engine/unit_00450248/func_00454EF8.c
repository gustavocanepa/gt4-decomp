#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00454EF8_arg0 {
    char pad0[0x1C];
    u16 unk1C;
    u16 unk1E;
    char pad20[0x24];
    s32 unk44;
};

s32 func_00454EF8(struct func_00454EF8_arg0 *arg0, s32 arg1, s32 arg2) {
    if ((arg2 < (s32) arg0->unk1E) && (arg1 < (s32) arg0->unk1C)) {
        return *(s32 *)((arg1 * 4) + *(s32 *)((arg2 * 4) + arg0->unk44));
    }
    return 0;
}
