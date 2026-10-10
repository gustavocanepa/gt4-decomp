#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00476FB8(s32);                         /* extern */

struct func_0047A890_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_0047A890(void *arg0) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x14;
    if ((((struct func_0047A890_arg0 *)arg0)->unk14 ^ 7) != 0) {
        func_00476FB8(temp_s0);
    }
    return temp_s0;
}
