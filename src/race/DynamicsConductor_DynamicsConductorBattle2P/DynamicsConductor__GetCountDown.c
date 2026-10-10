#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0034C1C8_arg0 {
    void *unk0;
    char pad4[0xF89C];
    s32 unkF8A0;
};

s32 DynamicsConductor__GetCountDown(void *arg0, s32 arg1) {
    s32 var_a2;

    var_a2 = M2C_FIELD(((struct func_0034C1C8_arg0 *)arg0)->unk0, s32 *, 0xBC);
    if ((arg1 >= 0) && (arg1 < ((struct func_0034C1C8_arg0 *)arg0)->unkF8A0)) {
        var_a2 += M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0xCBFC);
    }
    return var_a2;
}
