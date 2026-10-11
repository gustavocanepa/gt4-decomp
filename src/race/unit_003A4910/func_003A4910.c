#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_003A4910_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};
struct func_003A4910_var_v1_2 {
    s32 unk0;
    s32 unk4;
};

void func_003A4910(s8 *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a2;
    s32 var_v1;
    s8 *var_v1_2;
    s8 *base = arg0 + 4;
    var_v1 = ((struct func_003A4910_arg0 *)arg0)->unk1C;
    if (var_v1 >= 8) {
        var_v1_2 = arg0 + 0x24;
        var_a2 = 6;
        do {
            var_a2 -= 1;
            ((struct func_003A4910_var_v1_2 *)var_v1_2)->unk0 = (s32) ((struct func_003A4910_var_v1_2 *)var_v1_2)->unk4;
            var_v1_2 += 4;
        } while (var_a2 >= 0);
        temp_v0 = ((struct func_003A4910_arg0 *)arg0)->unk1C - 1;
        ((struct func_003A4910_arg0 *)arg0)->unk1C = temp_v0;
        var_v1 = temp_v0;
    }
    M2C_FIELD(((var_v1 * 4) + base), s32 *, 0x20) = arg1;
    ((struct func_003A4910_arg0 *)arg0)->unk1C = (s32) (((struct func_003A4910_arg0 *)arg0)->unk1C + 1);
    ((struct func_003A4910_arg0 *)arg0)->unk18 = (s32) (((struct func_003A4910_arg0 *)arg0)->unk18 + 1);
}
