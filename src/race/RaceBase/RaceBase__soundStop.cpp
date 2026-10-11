#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" {
s32 RaceCarSound__playStop(s32, s32);                /* extern */
s32 func_003B76F0(void *, s32, s32, s32); /* extern */

struct RaceBase__virtual_89_arg0 {
    char pad0[0x6C];
    void *unk6C;
};
struct RaceBase__virtual_89_temp_s1 {
    char pad0[0x60];
    s32 *unk60;
};

void RaceBase__soundStop(char *arg0) {
    s32 temp_v0;
    s32 var_s0;
    char *temp_s1;

    temp_s1 = (char *)(((struct RaceBase__virtual_89_arg0 *)arg0)->unk6C);
    var_s0 = 0;
    if (*((struct RaceBase__virtual_89_temp_s1 *)temp_s1)->unk60 > 0) {
        do {
            temp_v0 = var_s0 * 4;
            var_s0 += 1;
            RaceCarSound__playStop(*(s32 *)(temp_v0 + M2C_FIELD(((struct RaceBase__virtual_89_temp_s1 *)temp_s1)->unk60, s32 *, 8)) + 0x2900, 1);
        } while (var_s0 < *((struct RaceBase__virtual_89_temp_s1 *)temp_s1)->unk60);
    }
    func_003B76F0(temp_s1 + 0xF4, 0x18, -2, 0);
}

}
