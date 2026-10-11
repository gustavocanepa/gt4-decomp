#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0036F778(void *, f32);                     /* extern */

struct func_0036F980_arg0 {
    f32 unk0;
    f32 unk4;
    char pad8[0x1C];
    f32 unk24;
};

f32 func_0036F980(void *arg0, f32 fparg0) {
    f32 temp_f1;
    f32 var_f12;
    f32 var_f2;

    var_f12 = fparg0 / ((struct func_0036F980_arg0 *)arg0)->unk24;
    if (var_f12 <= 0.0f) {
        var_f12 = 0.0f;
    }
    if (var_f12 >= 1.0f) {
        var_f12 = 1.0f;
    }
    var_f2 = func_0036F778(arg0 + 8, var_f12);
    if (var_f2 <= 0.0f) {
        var_f2 = 0.0f;
    }
    if (var_f2 >= 1.0f) {
        var_f2 = 1.0f;
    }
    temp_f1 = ((struct func_0036F980_arg0 *)arg0)->unk4;
    return temp_f1 + ((((struct func_0036F980_arg0 *)arg0)->unk0 - temp_f1) * var_f2);
}
