#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_003A98E8(s32, f32, f32, f32, f32);     /* extern */

struct func_003A4E00_arg0 {
    char pad0[0x18];
    f32 unk18;
    f32 unk1C;
};

void func_003A4E00(char *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f15;
    f32 var_f1;

    var_f1 = fparg0;
    if (var_f1 == 0x0.0p+0f) {
        var_f1 = -0x1.0000000000000p+0f;
    }
    temp_f15 = ((struct func_003A4E00_arg0 *)arg0)->unk1C;
    func_003A98E8((s32)(arg0 + 0x54), fparg1, var_f1 - temp_f15, ((struct func_003A4E00_arg0 *)arg0)->unk18, temp_f15);
}

}
