#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001D1438(s32);                         /* extern */

struct func_005D1F10_arg0 {
    char pad0[0x50];
    s32 unk50;
};

s32 func_005D1F10(struct func_005D1F10_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk50;
    if (temp_v0 != 0) {
        func_001D1438(temp_v0);
    }
}
