#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005D5C80(void *);                          /* extern */

struct func_00209BF8_temp_s0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_00209BF8(s32 arg0) {
    struct func_00209BF8_temp_s0 *temp_s0;

    temp_s0 = arg0 + 0x20;
    return func_005D5C80(temp_s0) != temp_s0->unk4;
}
