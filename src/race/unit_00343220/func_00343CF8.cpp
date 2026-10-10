#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
void *func_00359510(s32);                           /* extern */

struct func_00343CF8_arg0 {
    char pad0[0x10];
    s32 unk10;
};
struct func_00343CF8_temp_v0 {
    char pad0[0x1];
    u8 unk1;
};

void func_00343CF8(char *arg0, f32 fparg0) {
    f32 *var_a0;
    s32 var_a1;
    char *temp_v0;

    temp_v0 = (char *)(func_00359510(((struct func_00343CF8_arg0 *)arg0)->unk10));
    var_a1 = 0;
    if (((struct func_00343CF8_temp_v0 *)temp_v0)->unk1 != 0) {
        var_a0 = (f32 *)(arg0 + 0x1C8);
        do {
            *var_a0 = fparg0;
            var_a1 += 1;
            var_a0 = (f32 *)((char *)var_a0 + 0xEC);
        } while (var_a1 < (s32) ((struct func_00343CF8_temp_v0 *)temp_v0)->unk1);
    }
}

}
