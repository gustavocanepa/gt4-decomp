#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003B76F0(s32, s32, s32, s32); /* extern */

struct func_00387E88_arg0 {
    char pad0[0x6C];
    s32 unk6C;
    char pad70[0xCE8];
    s32 unkD58;
};

s32 func_00387E88(struct func_00387E88_arg0 *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = arg0->unkD58;
    temp_v1 = temp_v0 - 1;
    if (temp_v0 > 0) {
        arg0->unkD58 = temp_v1;
        if (temp_v1 == 1) {
            func_003B76F0(arg0->unk6C + 0xF4, 1, 0, 0);
        }
    }
}
