#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00576AD8(s32, s32);                /* extern */

struct func_006101B8_arg0 {
    char pad0[0x80];
    s32 unk80;
};

s32 func_006101B8(void *arg0) {
    func_00576AD8(arg0 + 0x80, 0x40);
    return ((struct func_006101B8_arg0 *)arg0)->unk80;
}
