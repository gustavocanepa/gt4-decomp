#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0047B068();                            /* extern */

struct func_0047B208_arg1 {
    char pad0[0x70];
    s32 unk70;
};

s32 func_0047B208(s32 arg0, struct func_0047B208_arg1 *arg1) {
    arg1->unk70 = 1;
    func_0047B068();
    return arg0;
}
