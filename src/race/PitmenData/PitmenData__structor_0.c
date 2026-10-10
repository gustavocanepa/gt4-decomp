#include "types.h"
#include "gt4/PitmenData.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);


s32 func_003E73F0();                            /* extern */

extern char PitmenData__vtable[];
void PitmenData__structor_0(void *arg0) {
    s32 *var_v0;
    s32 var_a1;
    s32 var_v1;
    s8 *var_a0;

    func_003E73F0();
    ((struct PitmenData *)arg0)->unk8 = 0;
    var_a0 = arg0 + 0xC;
    ((struct PitmenData *)arg0)->unk6C = (s32)PitmenData__vtable;
    var_a1 = 0;
    do {
        var_v1 = 3;
        var_v0 = (s32 *)(var_a0 + 0xC);
loop_2:
        var_v1 -= 1;
        *var_v0 = 0;
        var_v0 -= 1;
        if (var_v1 >= 0) {
            goto loop_2;
        }
        var_a1 += 1;
        var_a0 += 0x10;
    } while (var_a1 < 6);
}
