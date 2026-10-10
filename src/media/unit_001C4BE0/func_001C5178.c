#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_001C5000(void *);                      /* extern */
s32 func_001C53C8(void *);                      /* extern */
s32 func_0058C110(s32, s32, s32, s32);      /* extern */

struct func_001C5178_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char pad1C[0x240];
    s32 unk25C;
    char pad260[0x18];
    s32 unk278;
};

void func_001C5178(void *arg0) {
    s32 var_a1;
    s32 var_a2;
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1 = ((struct func_001C5178_arg0 *)arg0)->unk14;
    var_a1 = 0;
    switch (temp_v1) {                              /* irregular */
    case 1:
        break;
    case 0:
        var_a1 = 1;
        break;
    case 2:
        var_a1 = 2;
        break;
    }
    temp_v1_2 = ((struct func_001C5178_arg0 *)arg0)->unk18;
    var_a2 = 0x3C;
    if (temp_v1_2 != 0) {
        var_a2 = ((temp_v1_2 ^ 1) == 0) ? 0x1E : 0x3C;
    }
    if (func_0058C110(((struct func_001C5178_arg0 *)arg0)->unk10, var_a1, var_a2, ((struct func_001C5178_arg0 *)arg0)->unk25C) == 0) {
        func_001C53C8(arg0 + 0x1C);
        func_001C5000(arg0);
        ((struct func_001C5178_arg0 *)arg0)->unk278 = 1;
    }
}
