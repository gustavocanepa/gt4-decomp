#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00354F30(s32, s32);                        /* extern */
s32 func_003BFD00(void *);                          /* extern */

struct DynamicsConductorSinglePlayer__virtual_10_temp_s1 {
    char pad0[0x8];
    s32 unk8;
};

s32 DynamicsConductorSinglePlayer__virtual_10(void **arg0, s32 arg1) {
    struct DynamicsConductorSinglePlayer__virtual_10_temp_s1 *temp_s1;

    temp_s1 = *arg0;
    if (func_003BFD00(temp_s1) != 0) {
        return func_00354F30(arg1, temp_s1->unk8);
    }
    return 1;
}
