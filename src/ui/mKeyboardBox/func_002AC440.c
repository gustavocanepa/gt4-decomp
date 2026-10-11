#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

struct func_002AC440_arg0 {
    char pad0[0xB0];
    s32 unkB0;
};

void func_002AC440(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if ((arg0 + 0xB0) != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0 = ((struct func_002AC440_arg0 *)arg0)->unkB0;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        ((struct func_002AC440_arg0 *)arg0)->unkB0 = temp_s0;
    }
}
