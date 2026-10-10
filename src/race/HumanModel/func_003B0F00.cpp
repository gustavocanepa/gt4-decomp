#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00454698(s32, s32, s32, s32);  /* extern */
s32 func_005FA820(s32, s32);                    /* extern */

extern char D_003B0490[];
extern char D_006A2448[];
struct func_003B0F00_arg0 {
    s32 unk0;
    char pad4[0x6AC];
    s32 unk6B0;
};

void func_003B0F00(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = ((struct func_003B0F00_arg0 *)arg0)->unk0;
    if (temp_v0 != 0) {
        temp_v0_2 = func_005FA820(temp_v0, (s32)D_003B0490);
        ((struct func_003B0F00_arg0 *)arg0)->unk6B0 = temp_v0_2;
        if (temp_v0_2 != 0) {
            func_00454698(((struct func_003B0F00_arg0 *)arg0)->unk0, temp_v0_2, (s32)D_006A2448, 4);
        }
    }
}
