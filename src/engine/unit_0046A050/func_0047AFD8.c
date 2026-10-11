#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00480FA0(s32, s32);                    /* extern */

struct func_0047AFD8_arg1 {
    char pad0[0x70];
    s32 unk70;
};

s32 *func_0047AFD8(s32 *arg0, struct func_0047AFD8_arg1 *arg1, s32 arg2, s32 arg3) {
    func_00480FA0(arg3, arg2);
    arg1->unk70 = 0;
    *arg0 = 1;
    return arg0;
}
