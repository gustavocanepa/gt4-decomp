#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef struct { u8 p0; u8 n; u8 pad[0x12]; u8 b[1]; } V;
V *func_00359510(s32);
struct func_003652C0_arg0 {
    s32 unk0;
    u8 unk4;
};

void func_003652C0(struct func_003652C0_arg0 *arg0, s32 arg1, u8 arg2) {
    u8 var_a0;
    V *temp_v0;
    if (arg0->unk4 == 0) {
        temp_v0 = func_00359510(arg0->unk0 + 0x600);
        var_a0 = 0;
        if (arg1 < temp_v0->n) {
            var_a0 = temp_v0->b[arg1];
        }
        M2C_FIELD((var_a0 + arg0->unk0), u8 *, 0x98) = arg2;
    }
}
