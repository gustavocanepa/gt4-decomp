#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0054B1A8(s32);                             /* extern */
s32 func_0054C2D0(s32);                             /* extern */

struct func_001D17F0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_001D17F0(struct func_001D17F0_arg0 *arg0) {
    if (func_0054B1A8(arg0->unk4) != 0) {
        return 0;
    }
    return func_0054C2D0(arg0->unk4);
}
