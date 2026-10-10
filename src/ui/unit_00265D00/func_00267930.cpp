#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */
s32 func_005769F0(s32);                     /* extern */
s32 func_00576A28(s32);                     /* extern */

extern char D_00830A18[];
struct func_00267930_arg0 {
    char pad0[0x68];
    s32 unk68;
};

void func_00267930(char *arg0, s32 *arg1) {
    s32 temp_a0;
    s32 temp_s0;

    func_005769F0((s32)D_00830A18);
    if ((arg0 + 0x68) != (char *)arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_a0 = ((struct func_00267930_arg0 *)arg0)->unk68;
        if (temp_a0 != 0) {
            func_003285F8(temp_a0);
        }
        ((struct func_00267930_arg0 *)arg0)->unk68 = temp_s0;
    }
    func_00576A28((s32)D_00830A18);
}

}
