#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0045CBB8_arg0 {
    char pad0[0x390];
    f32 unk390;
    f32 unk394;
};
struct func_0045CBB8_var_v0 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
};

void func_0045CBB8(void *arg0, f32 fparg0, f32 fparg1) {
    s32 var_v1;
    void *var_v0;

    var_v0 = arg0 + 8;
    var_v1 = 7;
    ((struct func_0045CBB8_arg0 *)arg0)->unk390 = (f32) (((struct func_0045CBB8_arg0 *)arg0)->unk390 + fparg0);
    ((struct func_0045CBB8_arg0 *)arg0)->unk394 = (f32) (((struct func_0045CBB8_arg0 *)arg0)->unk394 + fparg1);
    do {
        var_v1 -= 1;
        ((struct func_0045CBB8_var_v0 *)var_v0)->unk10 = (f32) (((struct func_0045CBB8_var_v0 *)var_v0)->unk10 + fparg0);
        ((struct func_0045CBB8_var_v0 *)var_v0)->unk14 = (f32) (((struct func_0045CBB8_var_v0 *)var_v0)->unk14 + fparg1);
        var_v0 += 0x44;
    } while (var_v1 >= 0);
}
