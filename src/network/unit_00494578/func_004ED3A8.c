#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

int func_00575E60(int, int);
s32 func_00571D60(s32);                         /* extern */

struct func_004ED3A8_arg0 {
    char pad0[0x50];
    s32 unk50;
};

void func_004ED3A8(struct func_004ED3A8_arg0 *arg0) {
    s32 var_v0;

    var_v0 = arg0->unk50;
    if (var_v0 == 0) {
        var_v0 = func_00575E60(0x40, 0x1340);
        arg0->unk50 = var_v0;
    }
    func_00571D60(var_v0);
    M2C_FIELD(arg0->unk50, s32 *, 0x1300) = 3;
    M2C_FIELD(arg0->unk50, s32 *, 0x130C) = 3;
    M2C_FIELD(arg0->unk50, s32 *, 0x1310) = 1;
    M2C_FIELD(arg0->unk50, s8 *, 0x1320) = 1;
}
